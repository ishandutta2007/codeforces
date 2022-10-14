#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <string>
#include <time.h>
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
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x;
ll  q, ans, w[100500], d[100500], p[100500], a[200500];
pii b[200500];
map<ll, ll> f;
ll fac[2005000], invfac[2005000];
ll binpow(ll x, ll y) {
    if (y == 0)
        return 1;
    ll tmp = binpow(x, y/2);
    tmp = tmp * tmp % MOD;
    if (y % 2 == 0)
        return tmp;
    return x * tmp % MOD;
}

ll C(ll n, ll k) {
    if (n < k || k < 0) {
        return 0;
    }
    return fac[n] * invfac[k] % MOD * invfac[n-k] % MOD;
}

ll T(ll n, ll k) {
    if (n == k)
        return 1;
    return k * binpow(n, n - k - 1) % MOD;
}
int main() {
    //freopen("input.txt", "r", stdin);
    ll x, y;

    fac[0] = invfac[0] = 1;
    for (int i = 1; i <= 2000000; i++) {
        fac[i] = fac[i-1] * i % MOD;
        invfac[i] = binpow(fac[i], MOD-2);
    }

    cin >> n >> m >> x >> y;
    ll ans = 0;
    for (int sz = 1; sz <= m; sz++) {
        if (n - sz - 1 < 0)
            break;
        ans += C(m-1, sz-1) * C(n-2, sz-1) % MOD * T(n, sz+1) % MOD * binpow(m, n - sz - 1) % MOD * fac[sz-1] % MOD;
    }
    cout << ans % MOD << endl;
    return 0;
}