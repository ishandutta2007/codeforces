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
ll i,n,j,k,k1,d,x,m,a[100500],dp[500500],b[10][10];
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
cin >> n;
pair <ll,ll> tmp;
vector <pair <ll,ll> > c;
for (i = 0; i < 4; i++)
{
    for (j = 0; j < 4; j++)
        cin >> a[j];
    tmp = mp(min(a[0],a[1]),min(a[2],a[3]));
    c.pb(tmp);
}
ll z = 0, rez = 0;
for (j = 0; j < c.size(); j++)
if (c[j].first + c[j].second <= n)
   {
    tmp = c[j];
    rez = j;
    z = 1;
    break;
   }
if (!z) cout << -1 << endl;
else
{
    cout << rez + 1 << " " << tmp.fi << " " << n - tmp.fi << endl;
}
return 0;
}