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
vector <ll> lal;
ll s,i,j,t,i1,m,n,k,x,y,x1,x2,y1,y2,rez,b,k1,k2,n1,m1;
map <ll, pair<ll,ll> > f;
map <ll,ll> g;
ll a[200500];
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
ll pro(ll x, ll y)
{
 if (x % y == 0) return y;
    else return x%y;
}
int main()
{
cin >> n;
a[0] = 0;
for (i = 1; i < 200000; i++)
    a[i] = (ll)1e+18;
ll pointer = 0;
j = 1;
for (i = 0; i < n; i++)
{
    cin >> t;
    if (t == 1) 
{
    cin >> k;
    pointer++;
    g[pointer] = k;
}
    else
{
    cin >> k1 >> k2;
    f[pointer].first = pointer;
    f[pointer].second = k1;
    pointer += k1*k2;
}
 a[j++] = pointer;
}
cin >> m;
//for (i = 0; i < j; i++)
    //cout << a[i] << " " << f[a[i]].fi << " " << f[a[i]].se << endl;
for (i = 0; i < m; i++)
{
    cin >> k;
    while (g[k] == 0)
          {
                k1 = a[upper_bound(a,a+100500,k-1) - a - 1];
                //cout << k1 << endl;
                k = pro( (k - f[k1].first), f[k1].second);
          }
    cout << g[k] << " ";
}
return 0;
}