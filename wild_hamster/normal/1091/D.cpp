#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgjs
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 998244353
typedef long long ll;
using namespace std;
ll n,m,k,x,  y, z, l, r, i, j, p[335], q;
ll fac[1005000], invfac[1005000];
set<ll> f;
ll binpow(ll x, ll y) {
    if (y == 0)
        return 1;
    ll tmp = binpow(x, y/2);
    tmp = tmp * tmp % MOD;
    if (y % 2 == 0)
        return tmp;
    return x * tmp % MOD;
}
int main() {
    //freopen("input.txt","r",stdin);
    fac[0] = 1;
    for (int i = 1; i <= 1000000; i++) {
        fac[i]  = fac[i-1] * i % MOD;
        invfac[i] = binpow(fac[i], MOD-2);
    }
    cin >> n;
    ll ans = fac[n];
    for (int i = 2; i <= n-1; i++) {
        ans = (ans + fac[n] * invfac[i] % MOD * (i-1) % MOD * (n-i) % MOD) % MOD;
    }
    cout << ans << endl;

    return 0;
}