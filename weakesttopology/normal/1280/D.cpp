#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

array<ll, 2> operator+(array<ll, 2> lhs, array<ll, 2> rhs) {
    lhs[0] += rhs[0], lhs[1] += rhs[1];
    return lhs;
}

ll get(array<ll, 2> v) {
    return v[0] + (v[1] > 0 ? +1 : 0);
}

ll solve() {
    int n, m;
    cin >> n >> m;

    vector<int> b(n), a(n);
    for (auto& x : b) cin >> x;
    for (auto& x : a) cin >> x;

    vector<vector<int>> E(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    vector<vector<array<ll, 2>>> dp(n);
    auto dfs = [&](auto&& self, int u, int p) -> void {
        dp[u] = {{0, a[u] - b[u]}};
        for (auto v : E[u]) if (v != p) {
            self(self, v, u);
            int k = (int)size(dp[u]), l = (int)size(dp[v]);
            vector<array<ll, 2>> dpnxt(k + l - 1, {-LINF, -LINF});
            for (int i = 0; i < k; ++i) {
                for (int j = 0; j < l; ++j) {
                    dpnxt[i + j] = max(dpnxt[i + j], dp[u][i] + dp[v][j]);
                }
            }
            swap(dp[u], dpnxt);
        }
        dp[u].push_back({0, 0});
        int k = (int)size(dp[u]);
        for (int i = k - 2; i >= 0; --i) {
            dp[u][i + 1] = max(dp[u][i + 1], {get(dp[u][i]), 0});
        }
    };
    dfs(dfs, 0, -1);
    return get(dp[0][m - 1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) cout << solve() << endl;

    exit(0);
}