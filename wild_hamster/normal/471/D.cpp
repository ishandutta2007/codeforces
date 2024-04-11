#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#define tr 1000000007
#define mp make_pair
#define tA 555
#define tB 666
#define AorB 777
typedef long long ll;
using namespace std;
ll a[800500],b[800500],t[800500],z[800500],rez,l,r,n,m,k,j,p,k1,k2,i;
ll Abs(ll x)
{
 if (x < 0) return -x;
    return x;
}
int main()
{
    cin >> n >> m;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < m; i++)
        cin >> b[i];
    for (i = 0; i < n + 2*m; i++)
        t[i] = -(ll)1e+16;
    for (i = 0; i < m - 1; i++)
        t[i] = b[i] - b[i+1];
    t[m-1] = -(ll)1e+15;
    for (i = 0; i < n - 1; i++)
        t[i+m] = a[i] - a[i+1];
    z[i] = 0;
    l = 0; r = 0;
    for (i = 1; i < n+m-1; i++)
    {
        if (i <= r) z[i] = min(z[i-l],r-i+1);
        while (t[z[i]] == t[i+z[i]])
              z[i]++;
        if (i + z[i] - 1 > r)
           r = i+z[i]-1, l = i;
    }
    rez = 0;
    for (i = m-1; i < m+n-1; i++)
        if (z[i] == m-1)
           rez++;
    cout << rez << endl;
    return 0;
}