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
#define MOD 1000000007
#define INF ((ll)1e+15)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
typedef long long ll;
using namespace std;
ll ans,x,i,j,n,k,k1,k2,m,d,v,y,z,a[15500],b[155];
ll binpow(ll x, ll y)
{
    if (y == 0)
       return 1;
    ll tmp = binpow(x,y/2);
    tmp *= tmp;
    tmp %= MOD;
    if (y%2 == 0)
       return tmp;
    tmp *= x;
    tmp %= MOD;
        return tmp;
}
ll inv(ll x)
{
    return binpow(x,MOD-2);
}
ll C(ll n, ll k)
{
    if (n == 0 && k == 0)
       return 1;
    if (k == 0)
       return 1;
    ll ans = 1;
    ll i;
    for (i = n-k+1; i <= n; i++)
        ans = (ans*i)%MOD;
    for (i = 1; i <= k; i++)
        ans = (ans*inv(i))%MOD;
    return ans;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    ll sum = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    ll ans = 1;
    for (i = n-1; i >= 0; i--)
    {
        ans = ans*C(sum-1,a[i]-1);
        ans %= MOD;
        sum -= a[i];
    }
    cout << ans << endl;
    return 0;
}