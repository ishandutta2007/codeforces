#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(10) << fixed;

    int n, k;
    cin >> n >> k;

    vector<double> p(n);
    for (auto& x : p) cin >> x;

    int null = (int)count(all(p), 0.0);

    if (n - null < k) {
        for (int u = 0; u < n; ++u) {
            double res = p[u] == 0.0 ? 0.0 : 1.0;
            cout << res << endl;
        }
        exit(0);
    }

    vector<int> popcount(1 << n, 0);
    vector<double> sum(1 << n, 0);

    for (int u = 0; u < n; ++u) sum[1 << u] = p[u];
    for (int mask = 1; mask < (1 << n); ++mask) {
        int lsb = mask & -mask;
        popcount[mask] = 1 + popcount[mask ^ lsb];
        if (mask != lsb) sum[mask] = sum[lsb] + sum[mask ^ lsb];
    }

    vector<double> dp(1 << n, 0);
    dp[0] = 1;

    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int u = 0; u < n; ++u) {
            if ((mask >> u & 1) || p[u] == 0) continue;
            int newmask = mask | (1 << u);
            dp[newmask] += dp[mask] * p[u] / (1 - sum[mask]);
        }
    }

    for (int u = 0; u < n; ++u) {
        double res = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (popcount[mask] == k && (mask >> u & 1)) res += dp[mask];
        }
        cout << res << endl;
    }

    exit(0);
}