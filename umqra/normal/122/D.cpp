#include <iostream>
#include <string>
using namespace std;
int chisla[1000];
bool check ( int i )
{
     bool h=true;
     while ( i>0 )
     {
           if ( i%10!=4&&i%10!=7 )
              h=false;
           i/=10;
     }    
     return h;
}
int main()
{
    string str;
    int n, m;
    cin >> n >> m >> str;
    for ( int i=0; i<str.length(); i++ )
    {
        if ( m==0 )
           break;
        if ( i<str.length()-1&&str[i]=='4'&&str[i+1]=='7' )
        {
             if ( (i+1)%2==0 )
             { 
                if ( i!=0&&str[i-1]=='4' )
                {
                     if ( m%2==1 )
                        str[i]='7';
                     cout << str;
                     cin >> str;
                     return 0;
                }
                else 
                {
                     str[i]='7';
                     m--;
                }
             }
             else 
             {
                  if ( i!=str.length()-2&&str[i+2]=='7' )
                  {
                      if ( m%2==1 )
                         str[i+1]='4';
                      cout << str;
                      cin >> str;
                      return 0;
                  }
                  else
                  {
                      str[i+1]='4';
                      m--;
                  }
             }
        }
    }
    cout << str;
    cin >>str;
    return 0;
}