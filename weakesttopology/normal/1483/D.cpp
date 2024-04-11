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

    constexpr int nmax = 600;
    ll d[nmax][nmax];
    fill(&d[0][0], &d[n - 1][n - 1] + 1, LINF);
    for (int u = 0; u < n; ++u) d[u][u] = 0;

    vector<array<int, 3>> edges(m);
    for (auto& [u, v, w] : edges)
    {
        cin >> u >> v >> w;
        --u, --v;
        d[u][v] = d[v][u] = w;
    }

    for (int k = 0; k < n; ++k)
        for (int u = 0; u < n; ++u)
            for (int v = 0; v < n; ++v)
                d[u][v] = min(d[u][v], d[u][k] + d[k][v]);

    int q;
    cin >> q;

    vector<vector<pair<int, int>>> queries(n);
    for (int z = 0; z < q; ++z)
    {
        int u, v, l;
        cin >> u >> v >> l;
        --u, --v;
        for (int t = 0; t < 2; ++t, swap(u, v))
            queries[u].emplace_back(v, l);
    }

    vector<int> good(m, false);

    for (int u = 0; u < n; ++u)
    {
        vector<ll> L(n, -LINF);
        for (auto [v, l] : queries[u])
            for (int y = 0; y < n; y++)
                L[y] = max(L[y], l - d[y][v]);
        for (int j = 0; j < m; ++j)
        {
            auto [x, y, w] = edges[j];
            if (d[u][x] + w <= L[y]) good[j] = true;
        }
    }

    int res = accumulate(all(good), 0);
    cout << res << endl;

    exit(0);
}