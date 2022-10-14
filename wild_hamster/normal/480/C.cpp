#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <deque>
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
typedef long long ll;
using namespace std;
int n,m,j,p,l,r,x,y,k1,k2,k3,k4,k,i,w,rez,b;
int a,dp[5005][5005],c[5005][5005];
int Abs(int x)
{
 if (x < 0) return -x;
 return x;
}
int main()
{
    cin >> n >> a >> b >> k;
    dp[0][a] = 1;
for (j = 0; j < k; j++)
{
    for (i = 1; i <= n; i++)
    if (i != b)
    {
       x = Abs(b-i) - 1;
       l = max(1, i-x);
       r = min(n,i+x);
       //cout << l << " " << r << " " << dp[j][i] << endl;
       
       c[j+1][l] += dp[j][i];
       c[j+1][l] %= tr;
       
       c[j+1][r+1] -= dp[j][i];
       c[j+1][r+1] += tr;
       c[j+1][r+1] %= tr;
       
       dp[j+1][i] -= dp[j][i];
       dp[j+1][i] += tr;
       dp[j+1][i] %= tr;
    }
    ll tmp = 0;
    for (i = 1; i <= n; i++)
    {
        tmp += c[j+1][i];
        tmp %= tr;
        
        dp[j+1][i] += tmp;
        dp[j+1][i] %= tr;
        //cout << c[j+1][i] << endl;
    }
}
ll sum = 0;
for (i = 1; i <= n; i++)
{
    sum += dp[k][i];
    sum %= tr;
}
    cout << sum << endl;
   return 0;
}