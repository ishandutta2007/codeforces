#include <iostream>
#include <algorithm>
using namespace std;
double mas[2000];
bool used[2000];
int main()
{
#ifndef ONLINE_JUDGE
    freopen ("grib.in", "r", stdin);
    freopen ("grib.out", "w", stdout);
#endif
    double n, t1, t2, k;
    cin >> n >> t1 >> t2 >> k;
    for ( int i = 0; i < n; i++ )
    {
        double u, v;
        cin >> u >> v;
        double h1 = (u * t1) * (100 - k) / 100 + (v * t2);
        double h2 = (v * t1) * (100 - k) / 100 + (u * t2);
        if ( h1 > h2 )
            mas[i] = h1;
        else
            mas[i] = h2;
        //cout << mas[i] << '\n';
    }
    for ( int i = 0; i < n; i++ )
    {
        double ma = -1;
        int ind;
        for ( int s = 0; s < n; s++ )
        {
            if ( !used[s] && mas[s] > ma )
            {
                ma = mas[s];
                ind = s;
            }
        }
        printf("%i %.2f\n", ind + 1, ma);
        used[ind] = 1;
    }
    return 0;
}