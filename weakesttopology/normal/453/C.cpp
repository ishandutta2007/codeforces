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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> E(n);

    for (int j = 0; j < m; ++j)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    vector<int> a(n);
    for (int u = 0; u < n; ++u) cin >> a[u];

    vector<int> vis(n, 0), P;

    auto insert = [&](int u)
    {
        P.push_back(u);
        a[u] ^= 1;
    };

    auto dfs = [&](auto& self, int u, int p) -> void
    {
        vis[u] = 1;
        insert(u);
        for (auto v : E[u])
        {
            if (not vis[v])
            {
                self(self, v, u);
                insert(u);
            }
        }
        if (a[u] == 1 && p != -1) insert(p), insert(u);
    };

    int rt = (int)distance(begin(a), find(all(a), 1));
    if (rt != n)
    {
        debug(rt);
        dfs(dfs, rt, -1);
        if (a[rt] == 1)
        {
            P.pop_back();
            a[rt] ^= 1;
        }

        if (count(all(a), 1))
        {
            for (int u = 0; u < n; ++u) debug(a[u]);
            cout << -1 << endl;
            exit(0);
        }
    }

    int k = size(P);

    cout << k << endl;
    for (int j = 0; j < k; ++j) cout << P[j] + 1 << "\n "[j + 1 < k];

    exit(0);
}