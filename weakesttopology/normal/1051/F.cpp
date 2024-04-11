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

bool chmin(auto& x, auto y) { return y < x ? (x = y, true) : false; }

template<typename T>
vector<T> dijkstra(int s, const auto& E)
{
    struct Data
    {
        T key;
        int v;
        Data(T key, int v) : key(key), v(v) { }
        bool operator<(const Data& rhs) const { return key > rhs.key; }
    };
    vector<T> dist(size(E), T(LINF));
    priority_queue<Data> pq;
    pq.emplace(dist[s] = 0, s);
    while (not empty(pq))
    {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : E[u])
        {
            if (chmin(dist[v], dist[u] + w))
                pq.emplace(dist[v], v);
        }
    }
    return dist;
}

// K >= floor(log(height))

template<typename T, int K>
struct LCA
{
private:
    const vector<vector<pair<int, T>>>& E;
    const int n;
    vector<int> L, R;
    vector<T> h;
    vector<array<int, K + 1>> up;
    int ct = 0;
    void dfs(int u, int p)
    {
        for (int i = 1; i <= K; ++i) up[u][i] = up[up[u][i-1]][i-1];
        L[u] = ct;
        for (auto [v, w] : E[u]) if (v != p)
        {
            h[v] = h[u] + w, up[v][0] = u;
            dfs(v, u);
        }
        R[u] = ct++;
    }
public:
    LCA(const auto& E, int root) : E(E), n(size(E)), L(n), R(n), h(n), up(n)
    {
        dfs(root, root);
    }
    bool is_ancestor(int u, int v) const
    {
        return L[u] <= L[v] && R[v] <= R[u];
    }
    int query(int u, int v) const
    {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = K; i >= 0; --i)
            if (!is_ancestor(up[u][i], v)) u = up[u][i];
        return up[u][0];
    }
    int query(int u, int v, int root) const
    {
        int w[3] = { query(u, v), query(u, root), query(v, root) };
        if (w[0] == w[1]) return w[2];
        else if (w[0] == w[2]) return w[1];
        else return w[0];
    }
    T distance(int u, int v) const
    {
        int w = query(u, v);
        return h[u] + h[v] - 2 * h[w];
    }
};

int main()
{ _
    int n, m; cin >> n >> m;

    vector<vector<pair<int, ll>>> E(n), F(n), G;

    for (int j = 0; j < m; ++j)
    {
        int u, v, w; cin >> u >> v >> w; --u, --v;
        E[u].emplace_back(v, w), E[v].emplace_back(u, w);
    }

    set<int> special_vtx;
    vector<tuple<int, int, ll>> special_edges;
    vector<int> h(n, -1);

    function<void(int, int)> dfs = [&](int u, int p)
    {
        for (auto [v, w] : E[u]) if (v != p)
        {
            if (h[v] == -1)
            {
                h[v] = h[u] + 1;
                F[u].emplace_back(v, w);
                F[v].emplace_back(u, w);
                dfs(v, u);
            }
            else if (h[v] > h[u])
            {
                special_vtx.insert({u, v});
                special_edges.emplace_back(u, v, w);
            }
        }
    };
    h[0] = 0;
    dfs(0, -1);

    LCA<ll, 17> lca(F, 0);

    vector<int> Id(n, -1);
    int ptr = 0;
    for (auto u : special_vtx) Id[u] = ptr++;

    G.resize(ptr + 2);

    for (auto u : special_vtx)
        for (auto v : special_vtx) if (u != v)
            G[Id[u]].emplace_back(Id[v], lca.distance(u, v));

    for (auto [u, v, w] : special_edges)
    {
        G[Id[u]].emplace_back(Id[v], w);
        G[Id[v]].emplace_back(Id[u], w);
    }

    int q; cin >> q;

    for (int z = 0; z < q; ++z)
    {
        int s, t; cin >> s >> t; --s, --t;

        auto Gcopy = G;

        if (not special_vtx.count(s)) Id[s] = ptr;
        if (not special_vtx.count(t)) Id[t] = ptr + 1;

        auto add_edge = [&](int u, int v)
        {
            if (u == v) return;
            ll d = lca.distance(u, v);
            Gcopy[Id[u]].emplace_back(Id[v], d);
            Gcopy[Id[v]].emplace_back(Id[u], d);
        };

        for (auto u : { s, t })
        {
            for (auto v : special_vtx)
                add_edge(u, v);
            for (auto v : { s, t })
                add_edge(u, v);
        }

        auto dist = dijkstra<ll>(Id[s], Gcopy);

        ll ans = dist[Id[t]];

        cout << ans << endl;
    }

    exit(0);
}