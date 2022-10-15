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

struct DSU
{
    vector<int> p, rk;
    int components;

    DSU(int n) : p(n, 0), rk(n, 0), components(n)
    {
        for (int i = 0; i < n; ++i) p[i] = -1;
    }
    int find(int i) { return p[i] < 0 ? i : p[i] = find(p[i]); }
    int find_size(int i) { return -p[find(i)]; }
    int (size)() const { return components; }
    void unite(int i, int j)
    {
        int x = find(i), y = find(j);
        if (rk[x] < rk[y]) swap(x, y);
        if (x != y)
        {
            --components;
            p[x] += p[y], p[y] = x;
            rk[x] += (rk[x] == rk[y]);
        }
    }
};

void compress(auto& v)
{
    sort(all(v));
    v.erase(unique(all(v)), end(v));
}

int main()
{ _
    int n, m; cin >> n >> m;

    vector edges(m, tuple(0, 0, 0));

    vector vtx(m, vector(0, 0));
    vector colors(n, vector(0, 0));

    for (auto& [u, v, c] : edges)
    {
        cin >> u >> v >> c; --u, --v, --c;
        vtx[c].push_back(u), vtx[c].push_back(v);
        colors[u].push_back(c), colors[v].push_back(c);
    }

    for (int c = 0; c < m; ++c) compress(vtx[c]);

    auto id = [&](int c, int u)
    {
        auto iter = lower_bound(all(vtx[c]), u);
        return (int)distance(begin(vtx[c]), iter);
    };

    for (int u = 0; u < n; ++u) compress(colors[u]);

    vector<DSU> dsu;

    for (int c = 0; c < m; ++c) dsu.push_back(DSU(size(vtx[c])));

    for (auto [u, v, c] : edges) dsu[c].unite(id(c, u), id(c, v));

    int q; cin >> q;

    vector queries(q, pair(0, 0));

    for (auto& [u, v] : queries)
    {
        cin >> u >> v; --u, --v;
        if (size(colors[u]) > size(colors[v])) swap(u, v);
    }

    auto cp_queries = queries; compress(cp_queries);

    int k = size(cp_queries);

    vector ans(k, 0);

    for (int j = 0; j < k; ++j)
    {
        auto [u, v] = cp_queries[j];

        for (auto c : colors[u]) if (binary_search(all(colors[v]), c))
            ans[j] += dsu[c].find(id(c, u)) == dsu[c].find(id(c, v));
    }

    for (int z = 0; z < q; ++z)
    {
        auto iter = lower_bound(all(cp_queries), queries[z]);
        int idx = (int)distance(begin(cp_queries), iter);
        cout << ans[idx] << endl;
    }

    exit(0);
}