#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
using namespace std;
#define mp make_pair 
#define INF ((ll)1e+9)
typedef unsigned long long ull;
typedef long long ll;
ll i,n,j,k,z,m,l,r,A,B,C,D,r1,r2,R1,R2,x,y,a[505],c[205][82005],ost[205],start[205];
string s1,s2;
ll gcd(ll a, ll b)
{
 if (a%b == 0)
    return b;
 return gcd(b,a%b);
}
ll Abs(ll x)
{
 if (x < 0)
    return -x;
 return x;
}

int main()
{
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 1; i <= n; i++)
    {
        c[i][0] = i;
        for (j = 1; j <= 3*(n+2); j++)
            c[i][j] = a[c[i][j-1]];
        for (j = 1; j <= n+1; j++)
        {
            ll flag = 0;
            for (k = j+1; k <= 2*n+1; k++)
                if (c[i][j] == c[i][k])
                {
                 start[i] = j;
                 ost[i] = k-j;
                 flag = 1;
                 break;
                }
            if (flag)
               break;
        }
    }
    ll ans = ost[1];
    for (i = 2; i <= n; i++)
        ans = ost[i]/gcd(ans,ost[i])*ans;
    ll ans2 = 0;
    ll max1 = 0;
    for (i = 1; i <= n; i++)
        max1 = max(max1,start[i]);
    while (ans2 < max1)
          ans2 += ans;
    cout << ans2 << endl;
    return 0;
}