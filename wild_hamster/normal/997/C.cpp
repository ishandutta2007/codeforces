#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 998244353
#define ROW 5
#define COL 30000
typedef long long ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,tot,x,y,INF, ans;
ll a[1000005], fac[1000005], p3[3005000], pp3[1005000], rev[1005000], invfac[1000500];
ll binpow (ll b, ll p)
{
    ll v = 1, c = b;
    for (int i = 0; i < 20; i++)
    {
        if (p & (1 << i))
        {
            v = (v * c) % MOD;
        }
        c = (c * c) % MOD;
    }
    return v;
}

int main() {

    //freopen("input.txt","r",stdin);
    cin >> n;
    rev[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        rev[i] = ((MOD - MOD / i) * rev[MOD % i]) % MOD;
    }
    p3[0] = 1;
    for (int i = 1; i <= n; i++)
        p3[i] = p3[i-1]*3%MOD;
    pp3[0] = 1;
    for (int i = 1; i <= n; i++)
        pp3[i] = pp3[i-1]*p3[n]%MOD;
    fac[0] = 1;
    invfac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = (fac[i-1]*i)%MOD;
        invfac[i] = (invfac[i-1]*rev[i])%MOD;
    }
    for (int i = 0; i <= n; i++) {
        if (a[n-i] != 0) {
            a[i] = a[n-i];
            continue;
        }
        a[i] = invfac[i]%MOD*invfac[n-i]%MOD;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll x = p3[i] * pp3[n-i] % MOD * a[i] % MOD;
        if (!(i&1))
            x = MOD-x;
        ans += x;
    }
    ans = (ans*2)%MOD;
    ll sum = 0;

    for (int i = n-1; i >= 0; i--) {
        ll sign = -1;
        if ((n-i)&1)
            sign = 1;
        ll x = p3[i];
        sum += sign * a[i] * (pp3[i] - binpow(x - 1, n));
        sum %= MOD;
        if (sum < 0)
            sum += MOD;
    }
    ans = (ans - sum*3)%MOD;
    ans %= MOD;
    if (ans < 0)
        ans += MOD;
    ans = ans*fac[n]%MOD;
    cout << ans << endl;
    return 0;
}