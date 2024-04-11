#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T>
bool chmin(T& x, T y) { return y < x ? (x = y, true) : false; }
const int inf = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll x;
    cin >> n >> x;
    vector<int> a(n);
    for (int u = 0; u < n; ++u) {
        cin >> a[u];
    }
    vector<vector<array<int, 2>>> E(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        E[u].push_back({v, w}), E[v].push_back({u, w});
    }
    vector<ll> h(n);
    auto dfs1 = [&](auto& self, int u, int p) -> void {
        for (auto [v, w] : E[u]) {
            if (v == p) continue;
            h[v] = h[u] + w;
            self(self, v, u);
        }
    };
    vector<vector<ll>> dist;
    for (int rt = 0; rt < n; ++rt) {
        h[rt] = 0;
        dfs1(dfs1, rt, -1); 
        dist.push_back(h);
    }
    vector<vector<vector<int>>> dp(n);
    vector<vector<int>> best(n);
    auto dfs2 = [&](auto& self, int u, int p) -> void {
        for (auto [v, w] : E[u]) {
            if (v == p) continue;
            self(self, v, u);
        }
        dp[u].assign(n, {inf});
        for (int c = 0; c < n; ++c) {
            if (dist[u][c] > x) continue;
            dp[u][c] = {inf, !a[c]};
            for (auto [v, w] : E[u]) {
                if (v == p) continue;
                int k = (int)size(dp[u][c]), l = (int)size(best[v]);
                vector<int> ndp(k + l - 1, inf);
                for (int i = 1; i < k; ++i) {
                    for (int j = 1; j < l; ++j) {
                        chmin(ndp[i + j], dp[u][c][i] + best[v][j]);
                        if (dist[v][c] <= x) chmin(ndp[i + j - 1], dp[u][c][i] + dp[v][c][j] - !a[c]);
                    }
                }
                swap(dp[u][c], ndp);
            }
            int k = (int)size(dp[u][c]);
            best[u].resize(max(size(dp[u][c]), size(best[u])), inf);
            for (int i = 0; i < k; ++i) {
                chmin(best[u][i], dp[u][c][i]);
            }
        }
    };
    dfs2(dfs2, 0, -1);
    int p = (int)count(begin(a), end(a), 1);
    int ans = best[0][p] == inf ? -1 : best[0][p];
    cout << ans << endl;
    exit(0);
}