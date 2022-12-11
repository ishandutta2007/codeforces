#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
double x[10000], y[10000];
int main()
{
    double n, k, rez=0;
    cin >> n >> k;
    cin >> x[0] >> y[0];
    for ( int i=1; i<n; i++ )
    {
        cin >> x[i] >> y[i];
        rez+=sqrt((x[i]-x[i-1])*(x[i]-x[i-1])+(y[i]-y[i-1])*(y[i]-y[i-1]));
    }
    cout << fixed << setprecision(8) << rez*k/50.;
    cin >> n;
    return 0;
}