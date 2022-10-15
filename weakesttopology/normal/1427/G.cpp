#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// atcoder Orz
template<typename Cap, typename Cost>
struct mcf_graph {
    inline static const Cap infcap = numeric_limits<Cap>::max();
    inline static const Cost infcost = numeric_limits<Cost>::max();
    struct Edge {
        int from, to;
        Cap cap, flow;
        Cost cost;
        Cap free() const { return cap - flow; }
    };
    struct Slope {
        Cap flow;
        Cost cost, slope;
    };
    // returns the minimum cost of 'flow' units of flow
    static Cost compute_cost(const vector<Slope>& slopes, Cap flow) {
        auto iter = lower_bound(begin(slopes), end(slopes), flow, [](Slope sl, Cap f) { return sl.flow < f; });
        if (iter == end(slopes)) return infcost;
        return iter->cost - (iter->flow - flow) * iter->slope;
    };
    // returns 'flow' value that minimizes above function (only useful with negative weights)
    static Cap find_minimum(const vector<Slope>& slopes) {
        auto iter = upper_bound(begin(slopes), end(slopes), 0, [](Cost c, Slope sl) { return c < sl.slope; });
        return prev(iter)->flow;
    }
    int N, M = 0;
    vector<Edge> edges;
    vector<vector<int>> E;
    mcf_graph(int N) : N(N), E(N) {}
    bool negative_cost = false;
    int add_edge(int u, int v, Cap cap, Cost cost) {
        if (cost < 0) negative_cost = true;
        edges.push_back({u, v, cap, 0, cost});
        edges.push_back({v, u, 0, 0, -cost});
        E[u].push_back(M++);
        E[v].push_back(M++);
        return M - 2;
    }
    vector<Cost> dual_feasible(int s) const {
        if (not negative_cost) return vector<Cost>(N);
        vector<Cost> d(N, infcost);
        vector<bool> on(N);
        queue<int> q;
        q.push(s);
        on[s] = true;
        d[s] = 0;
        while (not empty(q)) {
            int u = q.front();
            q.pop();
            on[u] = false;
            for (auto j : E[u]) {
                if (edges[j].cap == 0) continue;
                int v = edges[j].to;
                Cost nd = d[u] + edges[j].cost;
                if (nd < d[v]) {
                    d[v] = nd;
                    if (not on[v]) {
                        q.push(v);
                        on[v] = true;
                    }
                }
            }
        }
        return d;
    }
    // returns slope changing points and dual optimum
    pair<vector<Slope>, vector<Cost>> slope(int s, int t, vector<Cost> dual = {}, Cap limit = infcap) {
        if (empty(dual)) dual = dual_feasible(s);
        for (int j = 0; j < M; ++j) {
            edges[j].flow = 0;
        }
        vector<Cost> dist(N);
        vector<bool> vis(N);
        vector<int> p(N);
        vector<pair<Cost, int>> heap;
        vector<int> stk;
        heap.reserve(M);
        stk.reserve(M);
        auto dijkstra = [&]() {
            fill(begin(dist), end(dist), infcost);
            fill(begin(vis), end(vis), false);
            heap.emplace_back(dist[s] = 0, s);
            while (not (empty(heap) && empty(stk))) {
                int u;
                if (empty(stk)) {
                    u = heap[0].second;
                    pop_heap(begin(heap), end(heap));
                    heap.pop_back();
                }
                else {
                    u = stk.back();
                    stk.pop_back();
                }
                if (vis[u]) continue;
                vis[u] = true;
                if (u == t) break;
                for (auto j : E[u]) {
                    if (edges[j].free() == 0) continue;
                    int v = edges[j].to;
                    Cost nd = dist[u] + dual[u] - dual[v] + edges[j].cost;
                    if (nd < dist[v]) {
                        p[v] = j;
                        dist[v] = nd;
                        if (nd == dist[u]) {
                            stk.push_back(v);
                        }
                        else {
                            heap.emplace_back(-dist[v], v);
                            push_heap(begin(heap), end(heap));
                        }
                    }
                }
            }
            stk.clear();
            heap.clear();
            if (not vis[t]) return false;
            for (int u = 0; u < N; ++u) {
                if (not vis[u]) continue;
                dual[u] += dist[u] - dist[t];
            }
            return true;
        };
        vector<Slope> result = {{0, 0, -infcost}};
        Cap flow = 0;
        Cost cost = 0;
        while (flow < limit && dijkstra()) {
            Cap f = limit - flow;
            for (int u = t; u != s; u = edges[p[u]].from) {
                f = min(f, edges[p[u]].free());
            }
            for (int u = t; u != s; u = edges[p[u]].from) {
                edges[p[u]].flow += f;
                edges[p[u] ^ 1].flow -= f;
            }
            Cost d = dual[t] - dual[s];
            if (d == result.back().slope) {
                result.pop_back();
            }
            flow += f;
            cost += f * d;
            result.push_back({flow, cost, d});
            if (d >= 0) break;
        }
        return {result, dual};
    }
    // returns maximum flow, cost and dual optimum
    tuple<Cap, Cost, vector<Cost>> mincostflow(int s, int t, vector<Cost> dual_init = {}, Cap limit = infcap) {
        auto [slopes, dual] = slope(s, t, dual_init, limit);
        return {slopes.back().flow, slopes.back().cost, dual};
    }
};
const int dx[4] = {+1, -1, +0, -0};
const int dy[4] = {+0, -0, +1, -1};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n), id(n);
    int m = 0;
    for (int x = 0; x < n; ++x) {
        a[x].resize(n);
        id[x].resize(n);
        for (int y = 0; y < n; ++y) {
            cin >> a[x][y];
            //a[x][y] = (min(x, y) == 0 || max(x, y) == n - 1) ? rng() % 1'000'000'000 : -1 + !!(rng() % 5);
            if (a[x][y] != -1) id[x][y] = m++;
        }
    }
    const int src = m, snk = m + 1;
    using MCF = mcf_graph<int, ll>;
    MCF mcf(m + 2);
    ll cost = 0;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            if (a[x][y] == -1) continue;
            if (a[x][y] != 0) {
                mcf.add_edge(src, id[x][y], 1, a[x][y]);
                mcf.add_edge(id[x][y], snk, 1, -a[x][y]);
            }
            for (int t = 0; t < 4; ++t) {
                int nx = x + dx[t], ny = y + dy[t];
                if (min(nx, ny) < 0 || max(nx, ny) >= n || a[nx][ny] == -1) continue;
                if (a[nx][ny] != 0 && a[x][y] != 0) {
                    cost += abs(a[nx][ny] - a[x][y]);
                }
                else {
                    mcf.add_edge(id[x][y], id[nx][ny], 1, 0);
                }
            }
        }
    }
    cost /= 2;
    vector<ll> dist(m + 2, MCF::infcost);
    priority_queue<pair<ll, int>> pq;
    pq.emplace(0, src);
    while (not empty(pq)) {
        auto [d, u] = pq.top();
        pq.pop();
        if (-d > dist[u]) continue;
        for (int j : mcf.E[u]) {
            if (mcf.edges[j].cap == 0) continue;
            int v = mcf.edges[j].to;
            ll nd = dist[u] + mcf.edges[j].cost;
            if (nd < dist[v]) pq.emplace(-(dist[v] = nd), v);
        }
    }
    auto [slopes, dual] = mcf.slope(src, snk, dist);
    int flow = MCF::find_minimum(slopes);
    cost -= MCF::compute_cost(slopes, flow);
    cerr << "maxflow == " << slopes.back().flow << endl;
    cerr << "flow == " << flow << endl;
    cout << cost << '\n';
    exit(0);
}