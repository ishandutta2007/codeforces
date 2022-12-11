#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
long long neg[20], plu[20];
int main()
{
    long long nul=0;
    long long n, t=0;
    cin >> n;
    for ( int i=0; i<n; i++ )
    {
        int a;
        cin >> a;
        if ( a>0 )
            plu[a]++;
        else if ( a<0 )
            neg[-a]++;
        else
            nul++;

    }
    for ( int i=0; i<20; i++ )
    {
        t+=neg[i]*plu[i];
    }
    t+=nul*(nul-1)/2;
    cout << t;
    return 0;
}