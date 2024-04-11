#include <bits/stdc++.h>
#define ff(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    long double h, l;
    cin >> h >> l;

    cout << fixed << setprecision(6) << (l * l - h * h) / (2 * h);
    return 0;
}