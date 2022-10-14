#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
#define mp make_pair 
#define INF ((ll)1e+9)
typedef unsigned long long ull;
typedef long long ll;
ll i,n,j,k,x[100500],y[100500],z,m,l,r,a[228228],b[10],c[10];
string s;
ll Abs(ll x)
{
 if (x < 0)
    return -x;
 return x;
}
int main()
{
    ll ans = 0;
    cin >> m >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    ans = max(x[1] - 1 + y[1], m - x[n] + y[n]);
    for (i = 1; i < n; i++)
    {
        ll dif = x[i+1] - x[i];
        dif -= Abs(y[i+1]-y[i]);
        if (dif < 0)
        {
         cout << "IMPOSSIBLE" << endl;
         return 0;
        }
        ans = max(ans, dif/2 + max(y[i+1],y[i]));
    }
    cout << ans << endl;
    return 0;
}