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
ll n, x, k, z, m, pos, q, ans_v, y;
ll x1, p1, x2;
ll a[MAXN], b[MAXN], ans[MAXN];

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


ll prod[MAXN], sumprod[MAXN], sumsumprod[MAXN], sumprod2[MAXN];

ll find_sum(ll l, ll r) {
    ll last_shit = prod[r] * (r - l) % MOD;
    ll ff = (sumsumprod[r] - sumsumprod[l] - l * (sumprod2[r] - sumprod2[l]) + 3LL * MOD * MOD) % MOD;
    return (ff + last_shit) * inv(prod[r]) % MOD;
}

set<ll> f;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = a[i] * inv(100) % MOD;
    }
    prod[0] = 1;
    for (int i = 1; i <= n; i++) {
        prod[i] = prod[i-1] * a[i-1] % MOD;
    }
    ll cur = 1;
    for (int i = 0; i < n; i++) {
        ll curp = cur * (1 + MOD - a[i]) % MOD;
        sumprod[i] = curp;
        cur = cur * a[i] % MOD;
    }
    sumprod[n] = cur;

    for (int i = 0; i < n; i++) {
        sumprod2[i+1] = (sumprod2[i] + sumprod[i]) % MOD;
        sumsumprod[i+1] = (sumsumprod[i] + sumprod[i] * (i + 1)) % MOD;
    }

    f.insert(0);
    f.insert(n);
    ll ans = find_sum(0, n);
    for (int i = 0; i < q; i++) {
        ll x;
        cin >> x;
        x--;
        if (f.find(x) == f.end()) {
            auto it = f.upper_bound(x);
            ll r = *it;
            it--;
            ll l = *it;
            ans -= find_sum(l, r);
            ans += find_sum(l, x);
            ans += find_sum(x, r);
            f.insert(x);
        } else {
            f.erase(x);
            auto it = f.upper_bound(x);
            ll r = *it;
            it--;
            ll l = *it;
            ans += find_sum(l, r);
            ans -= find_sum(l, x);
            ans -= find_sum(x, r);
        }
        ans = (ans + 1LL * MOD * MOD) % MOD;
        cout << ans << "\n";
    }


    return 0;
}