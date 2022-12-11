#include <iostream>
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
    int n, in=0;
    cin >> n;
    for ( int i=4; i<1001; i++ )
    {
        if ( check (i) )
        {
             if ( n%i==0 )
             {
                cout << "YES";
                return 0;
             }   
        }
    }
    cout << "NO";
    return 0;
}