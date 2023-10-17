// Super-market Billing project using C++(OOPs) : saksham agarwal (rudra) HKRM

#include <bits/stdc++.h>

using namespace std;

class shopping
{
private:
    // product info:
    double pcode;
    float price;
    float dis;
    string pname;
    string email;
    string password;

public:
    // functions :
    void menu();
    void passwordA();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping ::menu() // main menu of the code:
{
m:
    int choice;

    cout << "\t\t\t\t\t_______________________________________________\n";
    cout << "\t\t\t\t\t                                               \n";
    cout << "\t\t\t\t\t                     HKRM                      \n";
    cout << "\t\t\t\t\t            Supermarket Main Menu              \n";
    cout << "\t\t\t\t\t_______________________________________________\n";
    cout << "\t\t\t\t\t                                               \n";
    cout << "\t\t\t\t\t|  1 . Administrator     |\n";
    cout << "\t\t\t\t\t|  2 . Buyer             |\n";
    cout << "\t\t\t\t\t|  3 . Exit              |\n\n";
    cout << "\t\t\t\t\t     Please Select !  ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        // only administrator can add or remove or edit product :
        passwordA();
        break;

    case 2:
        buyer();
        break;

    case 3:
        exit(0);
        break;

    default:
        cout << "Please select from the givin option   ";
        break;
    }
    goto m;
}

void shopping ::passwordA() // password creating or login for administrator
{
m:
    fstream datapassword;
    string email1;
    string password1;
    int choice;
    string e, p;

    cout << "\t\t\t\t\t________________    ___________________________\n";
    cout << "\t\t\t\t\t                                               \n";
    cout << "\t\t\t\t\t|  1 . Login             |\n";
    cout << "\t\t\t\t\t|  2 . sign in           |\n";
    cout << "\t\t\t\t\t|  3 . Exit              |\n\n";
    cout << "\t\t\t\t\t     Please Select !  ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        datapassword.open("datapassword.txt", ios::in);

        if (!datapassword)
        {
            cout << "\t\t\t\t Please sign in   \n\n";
            datapassword.close();
            goto m;
        }
        else
        {
            cout << "\t\t\t\t Please LogIn  \n";
            cout << "\t\t\t\t Enter Email ID:  ";
            cin >> email1;
            cout << "\t\t\t\tEnter Password:  ";
            cin >> password1;
            datapassword >> email >> password;
            while (!datapassword.eof())
            {
                if (email1 == email && password1 == password)
                {
                    datapassword.close();
                    administrator();
                }
                datapassword >> email >> password;
            }
            cout << "Invalid Credentials!\nPlease Try Again!\n\n";
            datapassword.close();
            break;
        }
        break;
    case 2:
        datapassword.open("datapassword.txt", ios::in);

        if (!datapassword)
        {
            datapassword.open("datapassword.txt", ios::app | ios::out);
            cout << "\t\t\t\t Enter Email ID:  ";
            cin >> email1;
            cout << "\t\t\t\t\tEnter Password:  ";
            cin >> password1;
            datapassword << " " << email1 << " " << password1 << "\n";
            datapassword.close();
        }
        else
        {
            cout << "\t\t\t\t Please veify first LogIn  \n";
            cout << "\t\t\t\t Enter already exisiting Email ID:  ";
            cin >> email1;
            cout << "\t\t\t\tEnter Password:  ";
            cin >> password1;
            datapassword >> email >> password;

            if (email1 == email && password1 == password)
            {
                datapassword.close();
                datapassword.open("datapassword.txt", ios::app | ios::out);
                cout << "\t\t\t\t Enter Email ID:  ";
                cin >> e;
                cout << "\t\t\t\tEnter Password:  ";
                cin >> p;
                datapassword << " " << e << " " << p << "\n";
                datapassword.close();
                cout << "\n\n\t\t\t Record inserted !" << endl;
            }
            else
            {
                cout << "Invalid Credentials!\nPlease Try Again!";
                datapassword.close();
                break;
            }
        }
        break;
    case 3:
        menu();
        break;
    default:
        cout << "Please select from the givin option   ";
    }
    goto m;
}

void shopping ::administrator()
{
m:
    int choice;
    cout << "\n\n\n\t\t\t\t Administrator menu" << endl;
    cout << "\n\t\t\t\t|        1. Add product             |\n";
    cout << "\n\t\t\t\t|        2. Delete Product          |\n";
    cout << "\n\t\t\t\t|        3. Update Product          |\n";
    cout << "\n\t\t\t\t|        4. Back to the main menu   |\n";

    cout << "\t\t\t\t\t     Please Select !   ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        rem();
        break;
    case 3:
        edit();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "Please select from the givin option   ";
    }
    goto m;
}

void shopping ::add() // this fuction will help to add new products
{
m:
    fstream data; // datashopping.txt contain info of products like product-code(pcode) , product-name(pname) , product-price(price) and discount-details(dis)
    double c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t\t\t Add new product";
    cout << "\n\n\t\t Product code of the product   ";
    cin >> pcode;
    cout << "\n\n\t\t Product name    ";
    cin >> pname;
    cout << "\n\n\t\t Product price   ";
    cin >> price;
    cout << "\n\n\t\t Product discount   ";
    cin >> dis;

    data.open("datashoppingit.txt", ios::in);

    if (!data)
    {
        data.open("datashoppingit.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if (token == 1)
        {
            goto m;
        }
        else
        {
            data.open("datashoppingit.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            data.close();
        }
    }
    cout << "\n\n\t\t\t Record inserted !" << endl;
}

void shopping::edit() // this fuction will help to edit products
{
    fstream data, data1;
    double pkey;
    double c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t\t Modify the record";
    cout << "\n\n\t\t\t Product code   ";
    cin >> pkey;

    data.open("datashoppingit.txt", ios::in);

    if (!data)
    {
        cout << "\n\n File doesn't exist !" << endl;
    }
    else
    {
        data1.open("datashoppingit1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t\t Product new code :  ";
                cin >> c;
                cout << "\n\n\t\t Product name  ";
                cin >> n;
                cout << "\n\n\t\t Product new price  ";
                cin >> p;
                cout << "\n\n\t\t Product discount  ";
                cin >> d;

                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\n\t\t Recod edited" << endl;
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("datashoppingit.txt");
        rename("datashoppingit1.txt", "datashoppingit.txt");
        if (token == 0)
        {
            cout << "\n\n\t\t\t\t Record not found !" << endl;
        }
    }
}

void shopping ::rem() // this fuction will help to remove a product products
{
    fstream data, data1;
    double pkey;
    int token = 0;
    cout << "\n\n\n\t\t\t Delete product";
    cout << "\n\n\n\t\t\t product code:  ";
    cin >> pkey;
    data.open("datashoppingit.txt", ios::in);

    if (!data)
    {
        cout << "\n\n File doesn't exist !" << endl;
    }
    else
    {
        data1.open("datashoppingit1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t\t\t Product deleted successfully" << endl;
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("datashoppingit.txt");
        rename("datashoppingit1.txt", "datashoppingit.txt");
        if (token == 0)
        {
            cout << "\n\n\t\t\t\t Record not found !" << endl;
        }
    }
}

void shopping ::buyer()
{
    int choice;
    string b;
    fstream buy;
    cout << "\n\n\n\t\t\t\t\t Buyer \n";
    cout << "\n\t\t\t\t\t\t Enter your name :   ";
    cin >> b;
    // databuyer.txt store the data for the administrator
    buy.open("databuyer.txt", ios::app | ios::out);
    buy << "\n";
    buy << b << "\n\t {";
    buy.close();
m:
    cout << "\n\t\t\t\t|        1. buy product      |\n";
    cout << "\n\t\t\t\t|        2. go back          |\n";
    cout << "\t\t\t\t\t     Please Select !   ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;
    default:
        cout << "Please select from the givin option   ";
    }
    goto m;
}

void shopping ::list() // this fuction will present the list of products
{
    fstream data;
    data.open("datashoppingit.txt", ios::in);
    cout << "\n\n\t\t|_______________________________________________________\n\n\n";
    cout << "proNo\t\tName\t\tPrice\n";
    cout << "\n\n\t\t|_______________________________________________________\n";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << endl;
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping::receipt() // this fuction will help to make receipt and also send a coppy of bill to databuyer.txt for administrator's obsevation
{
    fstream data, buy;

    double arc[100];
    int arq[100];
    string choice;
    int c = 0;
    double g = 0;
    char d;
    float amount = 0;
    float dis = 0;
    float total = 0;
    data.open("datashoppingit.txt", ios::in);

    if (!data)
    {
        cout << "\n\n File doesn't exist !";
    }
    else
    {
        data.close();

        list();

        cout << "\n\n\t\t|_______________________________________________________\n";
        cout << "\n\t\t                   Please place the order                 \n";
        cout << "\n\n\t\t|_______________________________________________________\n";
        do
        {
        m:
            cout << "\n\n Enter product code  ";
            cin >> arc[c];
            cout << "\n\n Enter the product quantity :   ";
            cin >> arq[c];
            c++;
            cout << "\n\n\t\t Do  you want to buy more ???  if yes press y else n   :  ";
            cin >> choice;
        } while (choice == "y");

        cout << "\n\n\n\t\tdo you want to delete any item ???  if yes press y else n   :";
        cin >> d;

        if (d == 'y')
        {
        s:
            cout << "\n\n\t\tEnter the product code of the item that needs to be deleted :   ";
            cin >> g;
            for (int i = 0; i < c; ++i)
            {
                if ((arc[i] == g))
                {
                    for (int w = i; w < c; ++w)
                    {
                        arc[w] = arc[w + 1];
                        arq[w] = arq[w + 1];
                    }
                }
            }
            c--;
            cout << "\n\n\t\t\t\t\t-----------Deleted Item------------";

            cout << "\n\n\n\t\tdo you want to delete anything else ???  if yes press y else n   :   ";
            cin >> d;
            if (d == 'y')
            {
                goto s;
            }
        }

        cout << "\n\n\t\t\t\t______________________RECEIPT___________________\n";
        cout << "\n\t\tProduct No\t\t Product Name\t\t Procuct quantity\t\t price\t\t amount\t\t amount with discount\n";

        for (int i = 0; i < c; i++)
        {
            data.open("datashoppingit.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == arc[i])
                {
                    amount = price * arq[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << "\n\t\t"
                         << pcode << "\t\t\t" << pname << "\t\t\t\t" << arq[i] << "\t\t\t " << price << "\t\t " << amount << "\t\t\t" << dis;
                }
                data >> pcode >> pname >> price >> dis;
            }
            data.close();
        }
    }
    cout << "\n\n__________________________________________________________________________________________________________________";
    cout << "\n Total Amount :" << total;

    buy.open("databuyer.txt", ios::app | ios::out);
    buy << "\n\n\t\t\t\t______________________RECEIPT___________________\n";
    buy << "\n\tProduct No\t Product Name\t Procuct quantity\t price\t amount\t amount with discount\n";

    for (int i = 0; i < c; i++)
    {
        data.open("datashoppingit.txt", ios::in);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == arc[i])
            {
                amount = price * arq[i];
                dis = amount - (amount * dis / 100);
                total = total + dis;
                buy << "\n\t"
                    << pcode << "\t\t  " << pname << "\t\t\t\t" << arq[i] << "\t\t\t\t " << price << "\t\t\t " << amount << "\t\t\t " << dis;
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
    }

    buy << "\n\n\t\t Total Amount :" << total << "\n \t }\n\n"
        << endl;
    buy.close();
}

int main()
{
    shopping s;
    s.menu();
    return 0;
}