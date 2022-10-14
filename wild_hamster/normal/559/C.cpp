#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <queue>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007LL
#define INF ((ll)1e+15)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
typedef long long ll;
using namespace std;
ll b[200500],fact[200500],invr[200500],i,j,n,k,k1,k2,m,x,y,l,r,a1,a2,a3,a4,a5,a6;
string s1,s2;
pair <ll,ll> a[200500];
map <pair<ll,ll>,ll> f;
ll binpow(ll x, ll y)
{
    if (y == 0)
       return 1;
    ll tmp = binpow(x,y/2);
    tmp *= tmp;
    tmp %= MOD;
    if (y%2 == 0)
       return tmp;
    return (x*tmp)%MOD;
}
ll inv(ll x)
{
    return binpow(x,MOD-2);
}
ll C(ll n, ll k)
{
 if (n < 0 || k < 0 || k > n)
    return 0;
 ll tmp = fact[n];
 tmp *= invr[k];
 tmp %= MOD;
 tmp *= invr[n-k];
 tmp %= MOD;
 return tmp;
}
int main()
{
    fact[0] = 1;
    invr[0] = 1;
    for (i = 1; i <= 200000; i++)
    {
        fact[i] = (fact[i-1]*i)%MOD;
        invr[i] = inv(fact[i]);
    }
    cin >> n >> m >> k;
    for (i = 0; i < k; i++)
        cin >> a[i].first >> a[i].second;
    ll ans = C(n+m-2,n-1);
    sort(a,a+k);
    for (i = 0; i < k; i++)
    {

        //cout << ans << endl;
        x = a[i].first;
        y = a[i].second;
        //cout << x << " " << y << endl;
        ll tmp = C(x+y-2,x-1);
        ll dob = C(n-x+m-y,n-x);
        //cout << tmp << " " << dob << endl;
        for (j = 0; j < i; j++)
        {
            ll xx = a[j].first;
            ll yy = a[j].second;
            tmp -= C(x+y-xx-yy,x-xx)*b[j];
            tmp += MOD*MOD;
            tmp %= MOD;
        }
        b[i] = tmp;
        ans -= dob*tmp;
        ans += MOD*MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}