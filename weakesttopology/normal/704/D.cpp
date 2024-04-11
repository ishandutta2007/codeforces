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

template<typename T>
struct Dinic
{
    struct Edge
    {
        int from, to;
        T cap, flow = 0;
        T free() { return cap - flow; }
        Edge(int u, int v, const T& cap) : from(u), to(v), cap(cap) {}
    };
    vector<Edge> edges;
    const T inf = numeric_limits<T>::max(), zero = 0;
    int n, m = 0;
    vector<vector<int>> E;
    vector<int> level, ptr;
    Dinic(int n) : n(n)
    {
        E.resize(n), level.resize(n), ptr.resize(n);
    }
    int add_edge(int u, int v, const T& cap)
    {
        assert(cap >= 0);
        edges.emplace_back(u, v, cap);
        edges.emplace_back(v, u, zero);
        E[u].push_back(m++);
        E[v].push_back(m++);
        return m - 2;
    }
    bool bfs(int s, int t)
    {
        fill(all(level), 0); level[s] = 1;
        static queue<int> q; q.push(s);
        while (not q.empty())
        {
            int u = q.front(); q.pop();
            for (auto idx : E[u])
            {
                int v = edges[idx].to;
                if (level[v] != 0 || edges[idx].free() <= 0) continue;
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
        return level[t] != 0;
    }
    T push(int u, int t, T pushed)
    {
        if (u == t || pushed == 0) return pushed;
        for (int& idx = ptr[u]; idx < size(E[u]); ++idx)
        {
            auto &edge = edges[E[u][idx]], &back = edges[E[u][idx] ^ 1];
            if (level[edge.to] != level[u] + 1 || edge.free() <= 0) continue;
            T pushing = push(edge.to, t, min(pushed, edge.free()));
            if (pushing == 0) continue;
            edge.flow += pushing, back.flow -= pushing;
            return pushing;
        }
        return 0;
    }
    void reset()
    {
        for (auto& edge : edges) edge.flow = 0;
    }
    T flow(int s, int t)
    {
        T f = 0;
        while (bfs(s, t))
        {
            fill(all(ptr), 0);
            while (T pushed = push(s, t, inf)) f += pushed;
        }
        return f;
    }
};

void fail()
{
    cout << -1 << endl;
    exit(0);
}

int main()
{ _
    int n, m; cin >> n >> m;
    ll r, b; cin >> r >> b;

    vector<pair<int, int>> pt(n);
    map<int, int> ctx, cty, deltax, deltay;

    for (auto& [x, y] : pt)
    {
        cin >> x >> y;
        ctx[x] += 1, cty[y] += 1;
        deltax[x] = deltay[y] = INF;
    }

    for (int j = 0; j < m; ++j)
    {
        int t, l, d; cin >> t >> l >> d;
        if (t == 1 && deltax.count(l)) deltax[l] = min(deltax[l], d);
        if (t == 2 && deltay.count(l)) deltay[l] = min(deltay[l], d);
    }

    int N = size(ctx) + size(cty) + 4;
    Dinic<int> dinic(N);

    vector<int> L(N);
    map<pair<int, int>, int> Id;
    int ptr = 0;

    auto get = [&](int x, int y)
    {
        pair<int, int> p(x, y);
        return Id.count(p) ? Id[p] : Id[p] = ptr++;
    };

    const int src = get(-1, -1), snk = get(-2, -2);
    const int super_src = get(-3, -3), super_snk = get(-4, -4);

    vector<tuple<int, int, int, int>> edges;

    for (auto [x, y] : pt)
    {
        edges.emplace_back(get(x, -1), get(-1, y), 1, 0);
    }
    for (auto [x, ct] : ctx)
    {
        int l = max((ct - deltax[x] + 1) / 2, 0);
        int r = min(ct, (ct + deltax[x]) / 2);
        edges.emplace_back(src, get(x, -1), r, l);
    }
    for (auto [y, ct] : cty)
    {
        int l = max((ct - deltay[y] + 1) / 2, 0);
        int r = min(ct, (ct + deltay[y]) / 2);
        edges.emplace_back(get(-1, y), snk, r, l);
    }
    vector<int> edge_id;

    for (auto [u, v, c, d] : edges)
    {
        if (c < d) fail();
        int id = dinic.add_edge(u, v, c - d);
        edge_id.push_back(id);
        L[u] -= d, L[v] += d;
    }

    int back_edge = dinic.add_edge(snk, src, INF);

    ll target = 0;

    for (int u = 0; u < N; ++u)
    {
        if (L[u] == 0) continue;

        if (L[u] > 0)
        {
            target += L[u];
            dinic.add_edge(super_src, u, +L[u]);
        }
        else
        {
            dinic.add_edge(u, super_snk, -L[u]);
        }
    }

    ll check_flow = dinic.flow(super_src, super_snk);
    ll back_flow = dinic.edges[back_edge].flow; 

    assert(ptr <= N);
    assert(accumulate(all(L), 0LL) == 0);

    if (check_flow != target) fail();

    ll max_flow = dinic.flow(src, snk);

    char rch = 'r', bch = 'b';
    if (r > b) swap(rch, bch), swap(r, b);

    ll cost = max_flow * (r - b) + n * b;

    string s(n, 'x');
    int ct_cheap = 0;

    for (int i = 0; i < n; ++i)
    {
        bool cheap = not dinic.edges[edge_id[i]].free();
        s[i] = cheap ? rch : bch;
        ct_cheap += cheap;
    }

    debug(check_flow);
    debug(back_flow);
    debug(max_flow);
    debug(ct_cheap);

    cout << cost << endl;
    cout << s << endl;

    exit(0);
}