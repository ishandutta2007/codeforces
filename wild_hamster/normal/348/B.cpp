#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <sstream>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll j,x,n,m,k,k1,k2,a[100500],used[100500],predok[100500],lcm[100500],y,d,l,r,i;
vector <ll> f[100500];
vector<pair <ll,ll> > b[100500];
ll gcd(ll a, ll b)
{
if (b==0) return a;
else return gcd(b,a%b);
}
void dfs(ll v, ll cnt)
{
 b[cnt].push_back( mp(predok[v],v) );
 for (ll i=0;i<f[v].size();i++)
 {
  int k = f[v][i];
  if (!used[k])
  {
   used[k] = 1;
   predok[k] = v;
   dfs(k,cnt+1);
  }
 }
}
int main()
{
cin >> n;
for (i=0;i<100500;i++) 
    lcm[i] = 1;
d = 0;
for (i=1;i<=n;i++) 
    {
     cin>>a[i];
     d+=a[i];
    }
for (i=0;i<n-1;i++)
    {
     cin >> k1 >> k2;
     f[k1].push_back(k2);
     f[k2].push_back(k1);
    }
used[1] = 1;
dfs(1,0);
ll rez = 0;
for (i=n+1;i>=0;i--)
{
sort(b[i].begin(),b[i].end());
ll x=b[i].size();
if (x>0)
   {
   ll sum, y = 1;
   ll min1 = sum = a[ b[i][0].se ];
   ll azaz = lcm[ b[i][0].se ];
   for (j=0;j<x-1;j++)
   {
   ll pr = b[i][j].fi, next_v = b[i][j+1].se, next_pr = b[i][j+1].fi; 
   if (pr == next_pr) 
      {
       min1 = min(min1,a[b[i][j+1].se]);
       y++;
       sum += a[next_v];
       azaz = (azaz * lcm[next_v]) / gcd(azaz, lcm[next_v]);
       if (azaz > (ll)1e+9) {cout<<d<<endl;return 0;}
      }
   else 
     {
      min1 = (min1 / azaz) * azaz;
      lcm[pr] = azaz * y;
      azaz = lcm[next_v];
      rez += sum - y*min1;
      a[pr] = y*min1;
      y = 1;
      sum = min1 = a[next_v];
     }
   }
   ll pr = b[i][j].fi;
   min1 = (min1 / azaz) * azaz;
   rez += sum-y*min1;
   a[pr] = y*min1;
   lcm[pr] = azaz*y;
   }
}
cout << rez << endl;
return 0;
}