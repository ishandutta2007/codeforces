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

void solve()
{
    int n, m; cin >> n >> m;

    vector<vector<int>> E(n);

    for (int j = 0; j < m; ++j)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    vector<int> vis(n, 0);

    function<void(int)> dfs = [&](int u)
    {
        vis[u] = -1;

        for (auto v : E[u]) if (vis[v] == -1) vis[u] = 1;
        for (auto v : E[u]) if (not vis[v]) dfs(v);
    };

    dfs(0);

    vector<int> ans;

    for (int u = 0; u < n; ++u)
    {
        if (vis[u] == 0)
        {
            cout << "NO" << endl;
            return;
        }
        else if (vis[u] == -1) ans.push_back(u);
    }

    int r = size(ans);

    cout << "YES" << endl;
    cout << r << endl;

    for (int i = 0; i < r; ++i)
    {
        cout << ans[i] + 1 << "\n "[i + 1 < r];
    }
}

int main()
{ _
    int t; cin >> t;
    while (t--) solve();
    exit(0);
}