#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

constexpr int nmax = 400;
ll dp[nmax + 2][nmax + 1];
ll f[nmax + 1], inv[nmax + 1], finv[nmax + 1], p[nmax + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll mod;
    cin >> n >> mod;

    for (int t = 0; t < 2; ++t) {
        f[t] = finv[t] = inv[t] = 1;
        p[t] = 1 << t;
    }
    for (int x = 2; x <= n; ++x) {
        f[x] = x * f[x - 1] % mod;
        inv[x] = mod - mod / x * inv[mod % x] % mod;
        finv[x] = inv[x] * finv[x - 1] % mod;
        p[x] = 2 * p[x - 1] % mod;

        assert(x * inv[x] % mod == 1);
        assert(f[x] * finv[x] % mod == 1);
    }
    auto C = [&](int n, int k){ return k > n ? 0 : f[n] * finv[k] % mod * finv[n - k] % mod; };

    dp[0][0] = 1;
    for (int x = 2; x <= n + 1; ++x) {
        for (int y = 0; y + 1 < x; ++y) {
            int len = x - y - 1;
            for (int k = 0; k <= y; ++k) {
                dp[x][k + len] += p[len - 1] * C(k + len, k) % mod * dp[y][k] % mod;
                dp[x][k + len] %= mod;
            }
        }
    }

    ll res = 0;
    for (int k = 0; k <= n; ++k)  {
        res += dp[n + 1][k];
        res %= mod;
    }
    cout << res << endl;

    exit(0);
}