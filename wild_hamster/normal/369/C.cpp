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
vector <ll> azaza;
ll i,n,j,k,k1,k2,l,r,d,sall,sk,x,m,p,a[200500],used[100500],predok[100500],vanya[100500];
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
vector <pair<ll,ll> > f[100500];
vector <ll> riven[100500];
vector <ll> rez;
map <ll,ll> g;
void dfs(ll v, ll stup)
{
  used[v] = 1;
  ll cnt = 0;
  riven[stup].pb(v);
  for (int i = 0; i < f[v].size(); i++)
      if (!used[f[v][i].fi] )
      {
       predok[f[v][i].fi] = v;
       dfs(f[v][i].fi,stup+1);
      }
}
int main()
{
cin >> n;
for (i = 0; i < n-1; i++)
{
    cin >> l >> r >> d;
    if (d == 2)
       {
             g[l*100500+r] = 1;
             g[r*100500+l] = 1;
       }
    f[l].pb(mp(r,d));
    f[r].pb(mp(l,d));
}  
d = 1;
dfs(1,0);
for (i = n; i >= 0; i--)
    for (j = 0; j < riven[i].size(); j++)
    {
   // cout << riven[i][j] << endl;
        if (vanya[riven[i][j]] == 0 && 
        g[riven[i][j]*100500 + predok[riven[i][j]] ])
        {
         vanya[ predok[riven[i][j]] ] = 1;
         rez.pb(riven[i][j]);
        } else
        if (vanya[riven[i][j]] == 1)
        vanya[predok[riven[i][j]]] = 1;
    }
cout << rez.size() << endl;
for (i = 0; i < rez.size(); i++)
    cout << rez[i] << " ";
return 0;
}