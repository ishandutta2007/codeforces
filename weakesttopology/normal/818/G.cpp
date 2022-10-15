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

auto chmin(auto& x, auto y) { return y < x ? x = y, true : false; }

template<typename T>
struct better_queue : public priority_queue<T>
{
    void clear() { this->c.clear(); }
};

template<typename Cap, typename Cost>
struct MCMF
{
    struct Edge
    {
        int from, to;
        Cap cap, flow = 0;
        Cost cost;
        Edge(int u, int v, Cap cap, Cost cost) :
            from(u), to(v), cap(cap), cost(cost) {}
        Cap free() const { return cap - flow; }
    };
    const int n;
    const Cap infcap = numeric_limits<Cap>::max();
    const Cost infcost = numeric_limits<Cost>::max();
    vector<Edge> edges;
    vector<vector<int>> E;

    MCMF(int n) : n(n)
    {
        E.resize(n);
        pi.resize(n), dist.resize(n);
        vis.resize(n), parent.resize(n);
    }

    int m = 0;
    bool negative = false;
    void add_edge(int u, int v, Cap cap, Cost cost)
    {
        edges.emplace_back(u, v, cap, cost);
        edges.emplace_back(v, u, 0, -cost);
        E[u].push_back(m++);
        E[v].push_back(m++);
        if (cost < 0) negative = true;
    }

    vector<Cost> pi, dist;
    vector<int> parent, vis;

    bool fix_potentials(int t)
    {
        if (not vis[t]) return false;
        for (int u = 0; u < n; ++u)
            if (vis[u]) pi[u] += dist[u] - dist[t];
        return true;
    }
    bool spfa(int s, int t)
    {
        fill(all(dist), 0), fill(all(vis), 1);

        dist[s] = 0;
        for (int u = 0; u < n; ++u)
        {
            if (u == s) continue;
            for (auto idx : E[u])
                if (edges[idx].free())
                    chmin(dist[edges[idx].to], dist[u] + edges[idx].cost);
        }

        return fix_potentials(t);
    }
    bool dijkstra(int s, int t)
    {
        fill(all(dist), infcost), fill(all(parent), -1), fill(all(vis), 0);
        struct Q
        {
            Cost key; int v;
            Q(Cost key, int v) : key(key), v(v) {}
            bool operator<(Q rhs) const { return key > rhs.key; }
        };
        static better_queue<Q> pq; pq.emplace(0, s); dist[s] = 0;
        while (not pq.empty())
        {
            auto [d, v] = pq.top(); pq.pop();
            if (vis[v]++) continue;
            if (v == t) { pq.clear(); break; }
            for (auto idx : E[v])
            {
                const auto& edge = edges[idx];
                if (vis[edge.to] || not edge.free()) continue;
                Cost cost = edge.cost + pi[v] - pi[edge.to];
                if (chmin(dist[edge.to], dist[v] + cost))
                {
                    parent[edge.to] = idx;
                    pq.emplace(dist[edge.to], edge.to);
                }
            }
        }
        return fix_potentials(t);
    }
    pair<Cap, Cost> flow(int s, int t, Cap K)
    {
        for (auto& edge : edges) edge.flow = 0;
        fill(all(pi), 0);
        if (negative) spfa(s, t);
        Cap flow = 0;
        Cost cost = 0;
        while (flow < K && dijkstra(s, t))
        {
            Cap pushed = K - flow;
            Cost price = 0;
            for (int v = t; v != s; v = edges[parent[v]].from)
                chmin(pushed, edges[parent[v]].free());
            for (int v = t; v != s; v = edges[parent[v]].from)
            {
                auto &edge = edges[parent[v]], &back = edges[parent[v] ^ 1];
                edge.flow += pushed, back.flow -= pushed;
                price += edge.cost;
            }
            flow += pushed, cost += price * pushed;
        }
        return { flow, cost };
    }
};

int main()
{ _
    int n; cin >> n;

    vector a(n, 0);
    for (auto& x : a) cin >> x;

    enum Type { IN = 0, OUT = 1 };
    auto id = [&](int i, Type t) { return 2 * i + t; };

    const int s = 2 * n, t = 2 * n + 1;
    MCMF<int, int> mcmf(2 * n + 2);

    for (int i = 0; i < n; ++i)
        mcmf.add_edge(id(i, IN), id(i, OUT), 1, -1);

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (abs(a[i] - a[j]) == 1 || (a[i] - a[j]) % 7 == 0)
                mcmf.add_edge(id(i, OUT), id(j, IN), 1, 0);

    for (int i = 0; i < n; ++i)
        mcmf.add_edge(s, id(i, IN), 1, 0), mcmf.add_edge(id(i, OUT), t, 1, 0);

    auto [flow, cost] = mcmf.flow(s, t, 4);

    debug(flow);
    debug(cost);

    int ans = -cost;

    cout << ans << endl;

    exit(0);
}