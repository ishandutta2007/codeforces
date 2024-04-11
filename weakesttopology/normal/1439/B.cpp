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
    int n, m, k; cin >> n >> m >> k;

    vector E(n, vector(0, 0));
    vector deg(n, 0);

    for (int j = 0; j < m; ++j)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].push_back(v), E[v].push_back(u);
        deg[u] += 1, deg[v] += 1;
    }

    for (int u = 0; u < n; ++u) sort(all(E[u]));

    using ii = pair<int, int>;

    priority_queue<ii, vector<ii>, greater<ii>> pq;

    for (int u = 0; u < n; ++u) pq.emplace(deg[u], u);

    vector vis(n, 0);

    auto clean = [&]()
    {
        while (not empty(pq) && (deg[pq.top().second] < k - 1 || vis[pq.top().second]))
        {
            int u = pq.top().second; pq.pop();
            if (not vis[u])
            {
                for (auto v : E[u])
                    if (not vis[v]) pq.emplace(--deg[v], v);
            }
            vis[u] = 1;
        }
        return true;
    };

    auto check_clique = [&](int u)
    {
        if (1LL * k * (k - 1) / 2 > m) return false;

        vector clique(1, u);

        for (auto v : E[u]) if (not vis[v]) clique.push_back(v);

        assert(size(clique) == k);

        for (auto v : clique)
            for (auto w : clique) if (v != w)
                if (not binary_search(all(E[v]), w))
                    return false;

        return true;
    };

    bool good = false;

    vector ans(0, 0);

    while (clean() && not empty(pq))
    {
        auto [d, u] = pq.top();
        assert(d == deg[u]), assert(not vis[u]);
        if (d == k - 1)
        {
            if (check_clique(u))
            {
                good = true;
                ans.push_back(u);
                for (auto v : E[u]) if (not vis[v]) ans.push_back(v);
                break;
            }
            else
            {
                deg[u] = -INF;
                pq.emplace(-INF, u);
            }
        }
        else if (d >= k)
        {
            good = true;
            for (int v = 0; v < n; ++v) if (not vis[v])
                ans.push_back(v);
            assert(size(ans) > k);
            break;
        }
        else assert(false);
    }

    if (not good) cout << -1 << endl;
    else
    {
        if (size(ans) == k)
            cout << 2 << endl;
        else
            cout << 1 << endl << size(ans) << endl;
        for (auto u : ans) cout << u + 1 << " ";
        cout << endl;
    }
}

int main()
{ _
    int t; cin >> t;
    while (t--) solve();
    exit(0);
}