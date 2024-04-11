#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

void solve() {
    int n;
    cin >> n;

    vector<array<ll, 2>> a(n);
    for (int u = 0; u < n; ++u) cin >> a[u][0] >> a[u][1];

    vector<vector<int>> E(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    vector<array<ll, 2>> dp(n);

    auto dfs = [&](auto& self, int u, int p) -> void {
        for (auto v : E[u]) {
            if (v == p) continue;
            self(self, v, u);
            for (auto t : {0, 1}) {
                ll cur = 0;
                for (auto s : {0, 1}) {
                    cur = max(cur, abs(a[u][t] - a[v][s]) + dp[v][s]);
                }
                dp[u][t] += cur;
            }
        }
    };
    dfs(dfs, 0, -1);

    cout << max(dp[0][0], dp[0][1]) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    exit(0);
}