#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
int len[10000];
int main()
{
    int n;
    cin >> n;
    int ma=0;
    for ( int i=0; i<n; i++ )
    {
        int a;
        cin >> a;
        len[a]++;
        if ( a>ma )
           ma=a;
    }
    int pairs=0, rez=0;
    for ( int i=0; i<=ma; i++ )
    {
        if ( len[i]/2>0 )
        {
             rez+=len[i]/4;
             if ( pairs==0 )  
               pairs+=(len[i]%4)/2;
             else
             {
                 if ( (len[i]%4)/2>0 )
                 {
                      rez++;
                      pairs=0;
                 }
             }
        }
    }
    
    cout << rez;
    cin >> n;
    return 0;
}