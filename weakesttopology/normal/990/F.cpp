#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{ _
    int n;
    cin >> n;

    vector<int> d(n);
    for (auto& x : d) cin >> x;

    if (accumulate(all(d), 0) != 0)
    {
        cout << "Impossible" << endl;
        exit(0);
    }

    int m;
    cin >> m;

    vector<vector<pair<int, int>>> E(n);
    vector<int> flow(2 * m, 0), vis(n, 0);

    for (int j = 0; j < m; ++j)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].emplace_back(v, j << 1);
        E[v].emplace_back(u, j << 1 | 1);
    }

    auto dfs = [&](auto& self, int u) -> int
    {
        vis[u] = 1;
        int res = d[u];
        for (auto [v, j] : E[u]) if (not vis[v])
        {
            res += flow[j] = self(self, v);
        }
        return res;
    };

    dfs(dfs, 0);

    cout << "Possible" << endl;
    for (int j = 0; j < m; ++j)
    {
        int f = flow[j << 1] - flow[j << 1 | 1];
        cout << f << endl;
    }

    exit(0);
}