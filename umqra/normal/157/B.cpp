#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
double r[1000];
double p=atan(1.)*4.;
int main()
{
    double rez=0;
    int n;
    cin >> n;
    for ( int i=0; i<n; i++ )
        cin >> r[i];
    sort(r, r+n);
    bool t=true;
    for ( int i=n-1; i>=0; i-- )
    {
        if ( t)
             rez+=r[i]*r[i]*p;
        else
            rez-=r[i]*r[i]*p;
        t=!t;
    }
    printf("%.6f", rez);
    cin >> n;
    return 0;
}