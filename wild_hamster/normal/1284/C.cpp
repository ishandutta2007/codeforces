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
#define MAXN 300500
ll MOD;
#define OFF 200001
ll N;
ll n, x, k, z, m, pos, q, ans_v, y;
ll a[300500], b[300500];
vector<ll> f, g;

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
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> MOD;
    precalc_facs();
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + (n - i + 1) * (n - i + 1) % MOD * fac[i] % MOD * fac[n-i] % MOD) % MOD;
    }
    cout << ans << "\n";
    return 0;

}