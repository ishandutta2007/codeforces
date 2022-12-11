#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
string rev ( string str )
{
       string rez="";
       for ( int i=str.length()-1; i>=0; i-- )
           rez+=str[i];
       return rez;
}
long long dec ( string str )
{
     long long mn=1;
     long long rez=0;
     for ( int i=str.length()-1; i>=0; i-- )
     {
         if ( str[i]=='1' )
            rez+=mn;
         mn*=2;
     }    
     return rez;
}
string b ( char a )
{
       string rez="";
       int code=(int)a;
       for ( int i=0; i<8; i++ )
       {
           rez+=(a%2)+'0';
           a/=2;
       }
       return rez;
}
int main()
{
    string str;
    getline(cin, str);
    long long t=0;
    for ( int i=0; i<str.length(); i++ )
    {
        string bin=b(str[i]);
        long long d=dec(bin);
        long long rez=t-d;
        long long mod=rez%256;
        if ( mod<0 )
           mod+=256;
        cout << mod << '\n';
        t=d;
    }
    cin >> str;
    return 0;
}