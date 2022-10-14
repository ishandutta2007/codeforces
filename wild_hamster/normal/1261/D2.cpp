#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 200500
#define MOD 998244353
#define OFF 2001
ll N;
ll n, x, k, z, m, pos, q, ans_v, y;
ll x1, p1, x2;

ll a[MAXN];
ll fac[MAXN], invfac[MAXN];

ll binpow(ll x, ll y) {
    if (y == 0) {
        return 1;
    }
    ll tmp = binpow(x, y / 2);
    tmp = tmp * tmp % MOD;
    if (y % 2) {
        return x * tmp % MOD;
    }
    return tmp;
}

ll inv(ll x) {
    return binpow(x, MOD-2);
}

ll C(ll n, ll m) {
    if (n < m) {
        return 0;
    }
    return fac[n] * invfac[m] % MOD * invfac[n-m] % MOD;
}

void precalc_facs() {
    fac[0] = invfac[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = fac[i-1] * i % MOD;
        invfac[i] = inv(fac[i]);
    }
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    if (k == 1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll m = 0;
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] != a[i+1]) {
            m++;
        }
    }
    if (a[0] != a[n-1]) {
        m++;
    }
    //cout << m << endl;

    precalc_facs();
    ll ans = 0;
    for (int i = 0; i <= m; i += 2) {
        ans = (ans + C(m, i) * C(i, i/2) % MOD * binpow(k-2, (m-i))) % MOD;
    }
    ans = (binpow(k, m) - ans + MOD) % MOD;
    ans = (ans * inv(2) ) % MOD;

    for (int i = 0; i < n-m; i++) {
        ans = ans * k % MOD;
    }
    cout << ans << "\n";


    return 0;
}