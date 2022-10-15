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
    int n; cin >> n;

    vector<vector<int>> E(n);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    vector<int> dist(n, -1), subtree(n, 0);

    function<void(int)> dfs = [&](int u)
    {
        subtree[u] = 1;
        for (auto v : E[u]) if (dist[v] == -1)
        {
            dist[v] = dist[u] + 1;
            dfs(v);
            subtree[u] += subtree[v];
        }
    };

    dist[0] = 0;
    dfs(0);

    ll cur = n + accumulate(all(dist), 0LL), ans = 0;

    function<void(int)> reroot = [&](int u)
    {
        ans = max(ans, cur);
        for (auto v : E[u]) if (subtree[v] < subtree[u])
        {
            int delta = n - 2 * subtree[v];
            cur += delta;
            reroot(v);
            cur -= delta;
        }
    };

    reroot(0);

    cout << ans << endl;

    exit(0);
}