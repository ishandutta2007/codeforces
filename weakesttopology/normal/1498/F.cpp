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

    int n, k;
    cin >> n >> k;

    vector<vector<int>> E(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    constexpr int kmax = 20;
    vector<array<int, 2 * kmax>> dp(n);

    auto dfs = [&](auto& self, int u, int p) -> void {
        dp[u][0] = a[u];
        for (auto v : E[u]) if (v != p) {
            self(self, v, u);
            rotate(begin(dp[v]), begin(dp[v]) + 2 * k - 1, begin(dp[v]) + 2 * k);
            for (int x = 0; x < 2 * k; ++x) dp[u][x] ^= dp[v][x];
        }
    };
    dfs(dfs, 0, -1);

    vector<int> g(n, 0);
    array<int, 2 * kmax> aux;

    auto reroot = [&](auto& self, int u, int p) -> void {
        for (int x = k; x < 2 * k; ++x) g[u] ^= dp[u][x];
        for (auto v : E[u]) if (v != p) {
            fill(all(aux), 0);
            for (int x = 0; x < 2 * k; ++x)
                aux[(x + 2) % (2 * k)] ^= dp[u][x] ^ dp[v][x];
            for (int x = 0; x < 2 * k; ++x) dp[v][x] ^= aux[x];
            rotate(begin(dp[v]), begin(dp[v]) + 1, begin(dp[v]) + 2 * k);
            self(self, v, u);
        }
    };
    reroot(reroot, 0, -1);

    for (int u = 0; u < n; ++u) {
        cout << !!g[u] << "\n "[u + 1 < n];
    }

    exit(0);
}