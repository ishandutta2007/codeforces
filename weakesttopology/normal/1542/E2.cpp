#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int nmax = 500;
ll mod;
ll add(ll x, ll y) {
    if (x < 0) x += mod;
    if (y < 0) y += mod;
    x += y;
    if (x >= mod) x -= mod;
    return x;
}
ll C[nmax + 1][nmax + 1], f[nmax + 1];
int maxinv[nmax + 1];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n >> mod;
    C[0][0] = f[0] = 1;
    for (int m = 1; m <= n; ++m) {
        C[m][0] = 1;
        for (int k = 1; k <= m; ++k) {
            C[m][k] = add(C[m - 1][k], C[m - 1][k - 1]);
        }
        f[m] = m * f[m - 1] % mod;
    }
    vector<ll> dp(1, 1);
    ll ans = 0;
    for (int m = 1; m <= n; ++m) {
        vector<ll> suffsum(size(dp));
        partial_sum(rbegin(dp), rend(dp), rbegin(suffsum), add);
        ll pref = C[n][n - m] * f[n - m] % mod;
        for (int x = 0; x < m; ++x) {
            ll cur = 0;
            for (int y = x + 1; y < m; ++y) {
                int z = maxinv[m - 1] + y - x + 1;
                if (z >= (int)size(dp)) continue;
                cur = add(cur, suffsum[z]);
            }
            ans = add(ans, pref * cur % mod);
        }
        maxinv[m] = m * (m - 1) / 2;
        int N = 2 * maxinv[m] + 1;
        vector<ll> a(N + 1), b(N + 1);
        auto update = [&](auto& v, int l, int r, ll value) {
            v[l] = add(v[l], value);
            v[r + 1] = add(v[r + 1], -value);
        };
        for (int x = -maxinv[m - 1]; x <= maxinv[m - 1]; ++x) {
            ll t = dp[maxinv[m - 1] + x];
            int zero = maxinv[m] + x;
            update(a, zero, zero + m - 1, -t);
            update(b, zero, zero + m - 1, t * (m + zero) % mod);
            update(a, zero - (m - 1), zero - 1, t);
            update(b, zero - (m - 1), zero - 1, (1 - (zero - (m - 1))) * t % mod);
        }
        partial_sum(begin(a), end(a), begin(a), add);
        partial_sum(begin(b), end(b), begin(b), add);
        dp.resize(2 * maxinv[m] + 1);
        for (int x = 0; x <= 2 * maxinv[m]; ++x) {
            dp[x] = a[x] * x + b[x];
            dp[x] %= mod;
        }
    }
    cout << ans << endl;
    exit(0);
}