#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <ios>
#include <conio.h>


using namespace std;

class admin
{
    public:
    void authenticate();
}a1;

class inventory : public admin
{
    public:
    string item_name;
    int price;
    int quant=0;
    inventory& operator=(inventory& a)
    {
        item_name=a.item_name;
        price = a.price;
        quant = a.quant;
        return *this;
    }
}x[100], y[100];

class create_menu : public inventory
{
    public:
    void display()
    {
        system("cls");
        cout<<"\t\tWELCOME TO STS RESTAURANT\n\n"<<endl;

        cout<<"\t\t*************************"<<endl;
        cout<<"\t\t*                       *"<<endl;
        cout<<"\t\t*                       *"<<endl;
        cout<<"\t\t*     ADMIN LOGIN       *"<<endl;
        cout<<"\t\t*                       *"<<endl;
        cout<<"\t\t*    PRESS ANY KEY      *"<<endl;
        cout<<"\t\t*      TO PROCEED       *"<<endl;
        cout<<"\t\t*                       *"<<endl;
        cout<<"\t\t*                       *"<<endl;
        cout<<"\t\t*************************"<<endl;
        getch();
        system("cls");
        choice();   
    }
    void choice()
    {
        int n;
        while (true)
        {
            cout << "\t\tSELECT APPROPRIATE OPTION - " << endl;
            cout << "\t\t1. ADD ITEM\n\t\t2. REMOVE ITEM \n\t\t3. UPDATE ITEM \n\t\t4. EXIT" << endl;
            cin >> n;
            if (n == 1)
            {
                add_item();
            }
            else if (n == 2)
            {
                remove();
            }
            else if (n == 3)
            {
                change();
            }
            else if (n == 4)
            {
                break; 
            }
            else
            {
                cout << "\t\tWRONG INPUT. ENTER AGAIN\n" << endl;
            }
        }
        if (n == 4)
        {
            a1.authenticate();
        }
    }
    void add_item()
    {
        while(true)
        {
            cout<<"\t\tENTER CATEGORY. PRESS 1 FOR FOOD, 2 FOR BEVERAGES, 3 TO EXIT - "<<endl;
            int s;
            int n;
            cin>>s;
            if(s==1)
            {
                cout<<"\nENTER NUMBER OF FOOD ITEMS YOU WANT TO ADD - "<<endl;
                cin>>n;
                cout<<"\nENTER FOOD NAMES AND PRICE - "<<endl;
                int i;
                for(i=0; i<n; i++)
                {
                    cout<<"\nITEM NUMBER "<<i+1<<" - \n\nNAME-";
                    cin>>x[i].item_name;
                    cout<<"ITEM PRICE - ";
                    cin>>x[i].price;
                }
            }
            else if(s==2)
            {
                cout<<"\nENTER NUMBER OF BEVERAGE ITEMS YOU WANT TO ADD - "<<endl;
                cin>>n;
                cout<<"\nENTER BEVERAGE NAMES AND PRICE - "<<endl;
                int i;
                for(i=0; i<n; i++)
                {
                    cout<<"\nITEM NUMBER "<<i+1<<" - \n\nNAME-";
                    cin>>y[i].item_name;
                    cout<<"ITEM PRICE - ";
                    cin>>y[i].price;
                }
            }
            else if(s==3)
            {
                break;
            }
            else
            {
                cout<<"\t\tWRONG INPUT. ENTER AGAIN\n"<<endl;
            }
        }
        cout<<"\n\t\tMENU CREATED. PRESS ANY KEY TO PROCEED."<<endl;
        getch();
        system("cls");
    }
    void change()
    {
        int n;
        while(true)
        {
            cout<<"\t\tENTER CATEGORY. PRESS 1 FOR FOOD, 2 FOR BEVERAGES, 3 TO EXIT - "<<endl;
            int s;
            int n;
            cin>>s;
            if(s==1)
            {
                int i;
                cout<<"LIST OF ITEMS\n"<<endl;
                for(i=0; i<100; i++)
                {
                    if(x[i].price==0)
                    {
                        break;
                    }
                    cout<<left<<setw(5)<<i+1<<setw(25)<<x[i].item_name<<setw(20)<<x[i].price<<endl;
                }
                cout<<"\nSELECT THE ITEM NUMBER - "<<endl;
                int l;
                cin>>l;
                cout<<"\nPRESS 1 TO CHANGE NAME OF ITEM OR 2 TO CHANGE PRICE"<<endl;
                while(true)
                {
                    cin>>n;
                    if(n==1)
                    {
                        cout<<"Enter new name - "<<endl;
                        cin>>x[l-1].item_name;
                        break;
                    }
                    if(n==2)
                    {
                        cout<<"Enter new price - "<<endl;
                        cin>>x[l-1].price;
                        break;
                    }
                    else
                    {
                        cout<<"\t\tWRONG INPUT. ENTER AGAIN\n"<<endl;
                    }
                }
            }
            else if(s==2)
            {
                int i;
                cout<<"LIST OF ITEMS\n"<<endl;
                for(i=0; i<100; i++)
                {
                    if(y[i].price==0)
                    {
                        break;
                    }
                   cout<<left<<setw(5)<<i+1<<setw(25)<<y[i].item_name<<setw(20)<<y[i].price<<endl;
                }
                cout<<"\nSELECT THE ITEM NUMBER - "<<endl;
                int k;
                cin>>k;
                cout<<"\nPRESS 1 TO CHANGE NAME OF ITEM OR 2 TO CHANGE PRICE"<<endl;
                while(true)
                {
                    cin>>n;
                    if(n==1)
                    {
                        cout<<"Enter new name - "<<endl;
                        cin>>y[k-1].item_name;
                        break;
                    }
                    if(n==2)
                    {
                        cout<<"Enter new price - "<<endl;
                        cin>>y[k-1].price;
                        break;
                    }
                    else
                    {
                        cout<<"\t\tWRONG INPUT. ENTER AGAIN\n"<<endl;
                    }
                }
            }
            else if(s==3)
            {
                break;
            }
            else
            {
                cout<<"\t\tWRONG INPUT. ENTER AGAIN\n"<<endl;
            }
        }
    }
    void remove()
    {
        int n;
        while(true)
        {
            cout<<"\t\tENTER CATEGORY. PRESS 1 FOR FOOD, 2 FOR BEVERAGES, 3 TO EXIT - "<<endl;
            int s;
            int n;
            cin>>s;
            if(s==1)
            {
                int i;
                cout<<"LIST OF ITEMS\n"<<endl;
                for(i=0; i<100; i++)
                {
                    if(x[i].price==0)
                    {
                        break;
                    }
                    cout<<left<<setw(5)<<i+1<<setw(25)<<x[i].item_name<<setw(20)<<x[i].price<<endl;
                }
                cout<<"\nSELECT THE ITEM NUMBER - "<<endl;
                int l;
                cin>>l;
                for(i=l-1; i<100; i++)
                {
                    x[i] = x[i+1];
                }
            }
            else if(s==2)
            {
                int i;
                cout<<"LIST OF ITEMS\n"<<endl;
                for(i=0; i<100; i++)
                {
                    if(y[i].price==0)
                    {
                        break;
                    }
                cout<<left<<setw(5)<<i+1<<setw(25)<<y[i].item_name<<setw(20)<<y[i].price<<endl;
                }
                cout<<"\nSELECT THE ITEM NUMBER - "<<endl;
                int k;
                cin>>k;
                for(i=k-1; i<100; i++)
                {
                    y[i] = y[i+1];
                }
            }
            else if(s==3)
            {
                break;
            }
            else
            {
                cout<<"\t\tWRONG INPUT. ENTER AGAIN\n"<<endl;
            }
        }
    }
}c1;

class menu : public admin
{
    public:
    void display();
}m1;

class bill : public menu
{
    public:
    void display(int j, string arr1[], int arr2[], int arr3[])
    {
        int i;
        int sum=0;
        cout<<"\t\t*************************"<<endl;
        cout<<"\t\t*                       *"<<endl;
        cout<<"\t\t*                       *"<<endl;
        cout<<"\t\t*      THANK YOU        *"<<endl;
        cout<<"\t\t*     FOR ORDERING      *"<<endl;
        cout<<"\t\t*                       *"<<endl;
        cout<<"\t\t*    PRESS ANY KEY      *"<<endl;
        cout<<"\t\t*     TO VIEW YOUR      *"<<endl;
        cout<<"\t\t*        BILL           *"<<endl;
        cout<<"\t\t*                       *"<<endl;
        cout<<"\t\t*************************"<<endl;
        getch();
        system("cls");
        cout << left << setw(10) << "S. NO." << setw(20) << "NAME" << setw(10) << "QUANTITY" << setw(15) << "UNIT PRICE" << setw(15) << "TOTAL PRICE\n" << endl;
        for(i=0; i<j; i++)
        {
            cout << left << setw(10) << i+1 << setw(20) << arr1[i] << setw(10) << arr3[i] << setw(15) << arr2[i] << setw(15) << arr2[i]*arr3[i] <<"\n" << endl;
            sum+=arr2[i]*arr3[i];
        }
        cout<<left<<setw(30)<<"\nTOTAL AMOUNT BEFORE TAX";
        cout<<right<<setw(40)<<sum;
        cout<<left<<setw(30)<<"\nCGST";
        cout<<right<<setw(40)<<sum*0.025;
        cout<<left<<setw(30)<<"\nSGST";
        cout<<right<<setw(40)<<sum*0.025;
        cout<<left<<setw(30)<<"\nTOTAL AMOUNT PAYABLE";
        cout<<right<<setw(40)<<sum + (sum*0.025) + (sum*0.025);
        cout<<"\n\nTHANKYOU FOR DINING WITH US. PRESS ANY KEY TO EXIT.";
        getch();
        system("cls");
    }
}b1;

void menu::display()
{
    system("cls");
    cout<<"\t\tWELCOME TO STS RESTAURANT\n\n"<<endl;
    cout<<"\t\t*************************"<<endl;
    cout<<"\t\t*                       *"<<endl;
    cout<<"\t\t*                       *"<<endl;
    cout<<"\t\t*      GOOD FOOD        *"<<endl;
    cout<<"\t\t*      GOOD VIBES       *"<<endl;
    cout<<"\t\t*                       *"<<endl;
    cout<<"\t\t*    EXCELLENT DEALS    *"<<endl;
    cout<<"\t\t*                       *"<<endl;
    cout<<"\t\t*                       *"<<endl;
    cout<<"\t\t*    PRESS ANY KEY      *"<<endl;
    cout<<"\t\t*      TO PROCEED       *"<<endl;
    cout<<"\t\t*                       *"<<endl;
    cout<<"\t\t*                       *"<<endl;
    cout<<"\t\t*************************"<<endl;
    getch();
    system("cls");
    cout<<"\t\tAVAILABLE CATEGORIES \n"<<endl;
    cout<<"\t\t1. FOOD\n\t\t2. BEVERAGES"<<endl;
    int n;
    int j=0;
    string arr1[200];
    int arr2[200];
    int arr3[200];
    while(true)
    {
        cout<<"\t\tENTER CATEGORY. PRESS 1 FOR FOOD, 2 FOR BEVERAGES, 3 TO EXIT - "<<endl;
        int s;
        int n;
        cin>>s;
        if(s==1)
        {
            int i;
            cout<<"\n\nLIST OF ITEMS\n"<<endl;
            for(i=0; i<100; i++)
            {
                if(x[i].price==0)
                {
                    break;
                }
                cout<<left<<setw(5)<<i+1<<setw(25)<<x[i].item_name<<setw(20)<<x[i].price<<endl;

            }
            cout<<"\nSELECT THE ITEM NUMBER - "<<endl;
            int l;
            cin>>l;
            cout<<"\nENTER THE QUANTITY - "<<endl;
            int u;
            cin>>u;
            arr1[j] = x[l-1].item_name;
            arr2[j] = x[l-1].price;
            x[l-1].quant += u;
            arr3[j] = x[l-1].quant; 

        }
        else if(s==2)
        {
            int i;
            cout<<"LIST OF ITEMS\n"<<endl;
            for(i=0; i<100; i++)
            {
                if(y[i].price==0)
                {
                    break;
                }
                cout<<left<<setw(5)<<i+1<<setw(25)<<y[i].item_name<<setw(20)<<y[i].price<<endl;
            }
            cout<<"\nSELECT THE ITEM NUMBER - "<<endl;
            int k;
            cin>>k;
            cout<<"\nENTER THE QUANTITY - "<<endl;
            int u;
            cin>>u;
            arr1[j] = y[k-1].item_name;
            arr2[j] = y[k-1].price;
            y[k-1].quant += u;
            arr3[j] = y[k-1].quant; 
        }
        else if(s==3)
        {
            break;
        }
        else
        {
            cout<<"\t\tWRONG INPUT. ENTER AGAIN\n"<<endl;
        }
        j++;
    }
    cout<<"\t\tPRESS ANY KEY TO MOVE FORWARD."<<endl;
    getch();
    system("cls");
    b1.display(j, arr1, arr2, arr3);
}

void admin::authenticate()
{
        int n;
        system("cls");
        while(true)
        {
            cout<<"\t\tWELCOME TO STS RESTAURANT\n\n"<<endl;
            cout<<"\t\tPress 1 for admin, 2 for customer, and 3 to exit - "<<endl;
            cin>>n;
            if(n==1)
            {
                c1.display();
                break;
            }
            else if(n==2)
            {
                m1.display();
                break;
            }
            else if(n==3)
            {
                break;
            }
            else
            {
                cout<<"\t\tWRONG INPUT. ENTER AGAIN\n"<<endl;
            }
        }
        
}
int main()
{
    a1.authenticate();
    return 0;
}
