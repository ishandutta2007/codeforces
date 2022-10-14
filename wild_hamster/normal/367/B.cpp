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
ll i,n,j,k,k1,d,x,m,p,a[200500],b[200500];
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
int main()
{
vector <ll> f;
map <ll,ll> g,g1;
cin >> n >> m >> p;
for (i = 0; i < n; i++)
    cin >> a[i];
    
for (i = 0; i < m; i++)
    {
     cin >> b[i];
     g[b[i]]++;
    }
for (i = 0; i < p; i++)
{
    ll tmp = 0;
    ll k = 0;
    for (j = i; tmp < m; j += p, tmp++)
    {
        if (j >= n) break;
           else
        if (g[a[j]])
        {
           k-=min(g[a[j]],g1[a[j]]);
           g1[a[j]]++;
           k+=min(g[a[j]],g1[a[j]]);
        }     
    }       
    if (k == m) f.pb(i+1);  
    if (tmp != m) continue;
    ll l = i; ll r = i + tmp*p;
    for (r = r; r < n; r+=p , l+=p)
    {
        if (g[a[l]]) 
        {
        k-=min(g[a[l]],g1[a[l]]);
         g1[a[l]]--;
        k+=min(g[a[l]],g1[a[l]]);
        }
        if (g[a[r]]) 
        {
        k-=min(g[a[r]],g1[a[r]]);
         g1[a[r]]++;
        k+=min(g[a[r]],g1[a[r]]);
        }
        if (k == m) f.pb(l+p+1);
    }
    for (l = l; l < n; l+=p)
    {
        if (g[a[l]])
         g1[a[l]]--;
    }
}
sort(f.begin(),f.end());
cout << f.size() << endl;
for (i = 0; i < f.size(); i++)
    cout << f[i] << " ";
return 0;
}