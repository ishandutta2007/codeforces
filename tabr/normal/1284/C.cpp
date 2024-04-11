#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

struct combination {
    ll mod;
    vector<ll> fac, finv, inv;

    combination(int n, ll m) : fac(n), finv(n), inv(n) {
        mod = m;
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < n; i++) {
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = mod - inv[mod % i] * (mod / i) % mod;
            finv[i] = finv[i - 1] * inv[i] % mod;
        }
    }

    ll c(int n, int k) {
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    combination com(1e6, m);

    ll ans = 0;
    rep(i, 0, n) {
        ll sum = com.fac[i + 1] * com.fac[n - i - 1] % m;
        sum = sum * (n - i) % m;
        sum = sum * (n - i) % m;
        ans = (ans + sum) % m;
        // cout << i << ' ' << sum << endl;
    }
    cout << ans << endl;

    return 0;
}