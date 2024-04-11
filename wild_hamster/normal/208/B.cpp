#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include <time.h>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
vector <ll> azaza;
ll z,max1,i,j,k,x,n,y,lp,rp,p,l,r,ql,qr,m,M_cnt,k1,k2,ost,ur,b[100500];
vector <vector <ll> > dp[60];
map <vector <ll>, ll> dp1[60];
vector <ll> a;
pair <ll,ll> c[10];
ll per(ll n, vector <ll> a);
bool cmp(ll a, ll b)
{
if (a/1000!=b/1000 && a%1000!=b%1000) return false;
return true;
}
void dfs(ll n)
{
ll i;
if (n < 3) return;
if (n == 3) 
 for (i = 0; i < dp[n].size(); i++)
  z = max(z, per((ll)3,dp[n][i]));
else     
{
         for (i = 0; i < dp[n].size();i++)
         {
         
          if (cmp(dp[n][i][1],dp[n][i][2]))
          {
           vector <ll> tmp;
           tmp.pb(a[n-4]); tmp.pb(dp[n][i][0]); tmp.pb(dp[n][i][2]);
           if (dp1[n][tmp] == 0)
           {
           dp1[n][tmp] = 1;
           dp[n-1].pb(tmp);
           }
          }
          if (cmp(a[n-4],dp[n][i][2]))
          {
           vector <ll> tmp;
          tmp.pb(dp[n][i][2]); tmp.pb(dp[n][i][0]); tmp.pb(dp[n][i][1]);
          if (dp1[n][tmp] == 0)
          {
          dp[n-1].pb(tmp);
          dp1[n][tmp] = 1;
          }
          }
         }
dfs(n-1);
}
}
ll per(ll n, vector <ll> a)
{
   ll i;  
 for (i = n-1; i > 0; i--)
     if (a[i]/1000!=a[i-1]/1000 && a[i]%1000!=a[i-1]%1000)
        return 0;
     else
        a[i-1] = a[i];
 return 1;
}
int main()
{
vector <ll> tmp;
    z = 0;
char s[5];
cin >> n;
for (i = 0; i < n; i++)
{
    cin >> s;
    a.pb(s[0]*1000 + s[1]);
}
if (n <= 3) { if (per(n,a)) cout << "YES" << endl; else cout << "NO" << endl; return 0;}
tmp.pb(a[n-3]); tmp.pb(a[n-2]); tmp.pb(a[n-1]);
dp[n].pb(tmp);
dfs(n);
if (z)
   cout << "YES";
else
    cout << "NO";
return 0;
}