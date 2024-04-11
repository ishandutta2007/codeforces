#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include <time.h>
#include <set>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 5000
#define NN 25000000
vector <ll> azaza;
ll rez,i,n,j,i1,j1,k,k1,k2,l,r,d,sall,sk,x,m,p,a[45][45],pre[42][42][42][42],dop[45][45];
ll dp[45][45],lastf,lasts,q;
ll gcd(ll a, ll b)
{
 if (b == 0) return a;
    else return gcd(b,a%b);
}
ll Abs(ll a)
{
if (a > 0) return a;
   return -a;
}
map <ll,ll> f;
char c;
int main()
{
cin >> n >> m >> q;
for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
        {
         cin >> c;
         a[i][j] = (int)c - (int)'0';
        }
for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
{
    for (i1 = i; i1 < n; i1++)
        for (j1 = j; j1 < m; j1++)
        {
            k = i1;
            ll rez = 0;
            while (k >= i && a[k][j1] == 0)
            {
                  dop[i1][j1]++;   
                  k--;
            }
            k = j1;
            ll minl = (ll)1e+11;
            while (k >= j && a[i1][k] == 0)   
                  {
                        minl = min(minl,dop[i1][k]);
                        rez += minl;
                        k--;
                  }     
            if (j1 == j && i1 == i) dp[i1][j1] = rez;
               else
            if (j1 == j) dp[i1][j1] = rez + dp[i1-1][j1];
               else
            if (i1 == i) dp[i1][j1] = rez + dp[i1][j1-1];
               else
            dp[i1][j1] = dp[i1][j1-1] + dp[i1-1][j1] - dp[i1-1][j1-1] + rez;
            pre[i][j][i1][j1] = dp[i1][j1];
        }
    for (i1 = 0; i1 < n; i1++)
        for (j1 = 0; j1 < m; j1++)
        {
            dop[i1][j1] = 0;
            dp[i1][j1] = 0;
        }
}
for (i = 0; i < q; i++)
{
    ll k1,k2,k3,k4;
    cin >> k1 >> k2 >> k3 >> k4;
    cout << pre[k1-1][k2-1][k3-1][k4-1] << endl;
}
return 0;
}