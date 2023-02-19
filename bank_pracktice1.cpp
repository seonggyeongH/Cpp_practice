#include <iostream>
#include <cstring> 

using namespace std;
const int NAME_LEN =20;

void showMenu(void);      //메뉴 출력 
void makeAccount(void);   // 계좌 개설을 위한 함수 
void depositMoney(void);  // 입금 
void withdrawMoney(void); // 출금 
void showAllAccInfo(void);// 잔액조회

enum {MAKE =1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct 
{
    int accID;     //계좌번호
    int balance;   //잔액
    char cusName[NAME_LEN] ; //고객 이름 
} Account;

Account accArr[100];  //Account 저장을 위한 배열 
int accNum =0;        // 저장된 account 수 

int main (void)
{
    int choice; 

    while (1){
        showMenu();
        cout<< "선택 : " ;
        cin >> choice;
        cout << endl;

        switch(choice)
        {
            case MAKE:
                makeAccount();
                break;
            case DEPOSIT:
                depositMoney();
                break;
            case WITHDRAW:
                withdrawMoney();
                break;
            case INQUIRE:
                showAllAccInfo();
                break;
            case EXIT:
                return 0;
            
            default :
                cout << "Illegal selection.."<<endl;
        }
    }


    return 0;
}

void showMenu(void)
{
    cout<< "------Menu------"<<endl;
    cout<< "1. 계좌 개설 " <<endl;
    cout<<"2. 입금" << endl;
    cout<< "3. 출금 " << endl;
    cout<< " 4. 계좌정보 전체 출력" <<endl;
    cout<< "5. 프로그램 종료" << endl;

}

void makeAccount(void)
{
    int id;
    char name[NAME_LEN];
    int balance;

    cout << "[계좌 개설]"<< endl;
    cout<< "계좌 ID: "; cin >> id;
    cout<< "이   름: "; cin >> name;
    cout<< "입금액:  "; cin >> balance;
    cout<<endl;

    accArr[accNum].accID =id;
    accArr[accNum].balance = balance;
    strcpy(accArr[accNum].cusName,name);
    accNum++;

}

void DepositMoney(void)
{
    int money;
    int id;
    cout<<"[입   금] "<<endl;
    cout<<"계좌 ID: "; cin>> id;
    cout<<"입금액 :"; cin >>money;

    for (int i=0; i<accNum; i++){
        if(accArr[i].accID ==id)
        {
            accArr[i].balance+= money;
            cout<<"입금 완료" <<endl<<endl;
            return;
        }
        cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
    }
}

void withdrawMoney(void)
{
    int money;
    int id;
    cout<<"[출   금]"<<endl;
    cout<<"계좌 ID : "; cin>> id;
    cout<<"출금액 : "; cin>> money;
    cout<<endl;

    for(int i=0; i<accNum; i++)
    {
        if(accArr[i].accID == id)
        {
            if(accArr[i].balance < money){
                cout<<"잔액부족"<<endl<<endl;
                return;
            }
            accArr[i].balance -=money;
            cout<<"출금완료"<<endl<<endl;
            return;

        }
        cout<<"유효하지 않은 ID 입니다"<<endl<<endl;
        
    }

}

void showAllAccInfo(void)
{
    for (int i=0; i<accNum; i++)
    {
        cout << "계좌 ID: "<<accArr[i].accID <<endl;
        cout<< "이  름: "<<accArr[i].cusName<<endl;
        cout<< "잔  액:  "<<accArr[i].balance<<endl;
    }



    
}