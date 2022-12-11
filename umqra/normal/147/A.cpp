#include <iostream>
#include <string>
using namespace std;
string str;
void del ()
{
     for ( int i=0; i<str.length(); i++ )
     {
         if ( str[i]==' '&&(str[i-1]==' '||str[i-1]=='_') )
            str[i]='_';
     }
     return;
}
int main()
{
    getline(cin, str);
    bool h=true;
    for ( int i=0; i<str.length(); i++ )
    {
        if ( isalpha(str[i]) )
        {
           if ( !h )
              cout << ' ';
           h=true;
           cout << str[i];
        }
        else
        {
            if ( isalpha(str[i-1]) )
               h=false;
            if ( str[i]!=' ' )
            {
                 h=true;
                 cout << str[i] << ' ';
            }
        }
    }
    cin >> str;
    return 0;
}