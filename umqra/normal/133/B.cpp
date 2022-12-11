#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
string brain ( char a )
{
       if ( a=='>' )
          return "1000";
       if ( a=='<' )
          return "1001";
       if ( a=='+' )
          return "1010";
       if ( a=='-' )
          return "1011";
       if ( a=='.' )
          return "1100";
       if ( a==',' )
          return "1101";
       if ( a=='[' )
          return "1110";
       return "1111";      
}
long long dec ( string str )
{
     long long rez=0;
     long long mn=1;
     for ( int i=str.length()-1; i>=0; i-- )
     {
         if ( str[i]=='1' )
         {
            rez+=mn;
            rez%=1000003;
         }
         mn*=2;
         mn%=1000003;
     }
     return rez;
}
int main()
{
    string all_bin="";
    long long a=0;
    string str;
    cin >> str;
    for ( int i=0; i<str.length(); i++ )
    {
        string bin=brain(str[i]);
        all_bin+=bin;
    }
    //cout << all_bin;
    long long rez=dec(all_bin);
    cout << rez%1000003;
    cin >> str;
    return 0;
}