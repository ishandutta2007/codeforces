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

    vector<bool> special(n, false);

    for (int i = 0; i < 2 * k; ++i) {
        int u;
        cin >> u;
        --u;
        special[u] = true;
    }

    vector<vector<int>> E(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    ll res = 0;

    auto dfs = [&](auto& self, int u, int p) -> int {
        int cnt = special[u];
        for (auto v : E[u]) if (v != p) {
            int cntv = self(self, v, u);
            res += min(cntv, 2 * k - cntv);
            cnt += cntv;
        }
        return cnt;
    };
    dfs(dfs, 0, -1);

    cout << res << endl;

    exit(0);
}