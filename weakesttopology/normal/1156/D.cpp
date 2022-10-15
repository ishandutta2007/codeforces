#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) (X).begin(), (X).end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{ _
    int n; cin >> n;

    vector E(n, vector(0, pair(0, 0)));

    for (int i = 0; i < n - 1; ++i)
    {
        int x, y, c; cin >> x >> y >> c; --x, --y;
        E[x].emplace_back(y, c), E[y].emplace_back(x, c);
    }

    vector p(n, vector(2, 0));

    for (int u = 0; u < n; ++u) p[u] = { u, u };

    vector vis(n, vector(2, 0LL));

    function<ll(int, int)> dfs = [&](int u, int d)
    {
        ll sz = vis[u][d] = 1LL;
        for (auto [v, c] : E[u])
            if (not vis[v][d] && c == d)
            {
                p[v][d] = p[u][d];
                sz += dfs(v, c);
            }
        return sz;
    };

    for (int u = 0; u < n; ++u)
        for (int d = 0; d < 2; ++d)
            if (not vis[u][d]) vis[u][d] = dfs(u, d);

    for (int u = 0; u < n; ++u)
        for (int d = 0; d < 2; ++d)
            vis[u][d] = vis[p[u][d]][d];

    ll ans = 0LL;

    for (int u = 0; u < n; ++u)
    {
        for (int d = 0; d < 2; ++d)
            if (p[u][d] == u) ans += vis[u][d] * (vis[u][d] - 1);

        ans += (vis[u][0] - 1) * (vis[u][1] - 1);
    }

    cout << ans << endl;

    exit(0);
}