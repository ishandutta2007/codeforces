#include <iostream>
#include <string>
using namespace std;
int mas[1000];
void parse ( string str, int start )
{
     int i;
     for ( i=start; i<str.length(); i++ )
     {
         if ( str[i]=='.' )
            break;
     }
     i-=3;    
     while ( i>start )
     {
           mas[i]=1;
           i-=3;
     }
     return;
}
int main()
{
    int start=0;
    string str;
    cin >> str;
    int count=0;
    if ( str[0]=='-' )
    {
         start=1;
         cout << "($";
    }
    else
        cout << "$";
    parse(str, start);
    for ( int i=start; i<str.length(); i++ )
    {
        if ( count>2 )
           break;
        if ( count )
           count++;
        if ( str[i]=='.' )
           count=1;
        if ( mas[i] )
           cout << ',';
        cout << str[i];
    }
    if ( !count )
       cout << ".00";
    if ( count==1 )
       cout << "00";
    if ( count==2 )
       cout << "0";
    if ( start )
       cout << ')';
    cin >> str;
    return 0;
}