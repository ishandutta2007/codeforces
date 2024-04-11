#include <bits/stdc++.h>
using namespace std;
template <class CapType = int, class CostType = int>
struct MinCostFlow {
    struct Edge {
        CapType cap, flow;
        CostType cost;
        size_t to, rev;

        Edge(size_t to, size_t rev, CapType cap, CostType cost) : 
            to(to), rev(rev), cap(cap), cost(cost), flow(0) {}
    };

    vector<vector<Edge>> g;
    vector<tuple<CapType, CostType, CostType>> curve;
    size_t num_node;

    MinCostFlow() = default;
    MinCostFlow(size_t n) : num_node(n), g(n) {}

    void AddEdge(size_t from, size_t to, CapType cap, CostType cost) {
        g[from].emplace_back(to, g[to].size(), cap, cost);
        g[to].emplace_back(from, g[from].size() - 1, 0, -cost);
    }

    pair<CapType, CostType> operator()(size_t src, size_t snk) {
        constexpr CostType kInf = numeric_limits<CostType>::max();
        vector<CostType> dist(num_node);
        vector<bool> inque(num_node);
        vector<size_t> pv(num_node), ed(num_node);
        CapType sum_flow = 0;
        CostType sum_cost = 0;
        curve.clear();
        while (true) {
            fill(dist.begin(), dist.end(), kInf);
            fill(inque.begin(), inque.end(), false);
            dist[src] = 0;
            vector<size_t> que(1, src);
            for (size_t it = 0; it < que.size(); ++it) {
                size_t x = que[it];
                inque[x] = false;
                for (size_t i = 0; i < g[x].size(); ++i) {
                    if (g[x][i].cap == 0) continue;
                    if (dist[g[x][i].to] > dist[x] + g[x][i].cost) {
                        dist[g[x][i].to] = dist[x] + g[x][i].cost;
                        pv[g[x][i].to] = x;
                        ed[g[x][i].to] = i;
                        if (!inque[g[x][i].to]) {
                            inque[g[x][i].to] = true;
                            que.push_back(g[x][i].to);
                        }
                    }
                }
            }
            if (dist[snk] == kInf) break;
            CapType flow = numeric_limits<CapType>::max();
            for (size_t x = snk; x != src; x = pv[x]) flow = min(flow, g[pv[x]][ed[x]].cap);
            for (size_t x = snk; x != src; x = pv[x]) {
                g[pv[x]][ed[x]].cap -= flow;
                g[pv[x]][ed[x]].flow += flow;
                g[x][g[pv[x]][ed[x]].rev].cap += flow;
                g[x][g[pv[x]][ed[x]].rev].flow -= flow;
            }
            curve.emplace_back(sum_flow, sum_cost, dist[snk]);
            sum_flow += flow;
            sum_cost += flow * dist[snk];
        }
        curve.emplace_back(sum_flow, sum_cost, 0);
        return make_pair(sum_flow, sum_cost);
    }

    CostType GetCost(CapType cap) const {
        auto it = lower_bound(curve.begin(), curve.end(), make_tuple(cap, numeric_limits<CostType>::min(), 0));
        assert(it != curve.end());
        return get<1>(*it) + get<2>(*it) * (cap - get<0>(*it));
    }

    CapType GetResidual(size_t from, size_t to) const {
        for (const Edge &e : g[from]) {
            if (e.to == to) return e.cap;
        }
        return -1;
    }

    CapType GetFlow(size_t from, size_t to) const {
        for (const Edge &e : g[from]) {
            if (e.to == to) return e.flow;
        }
        return -1;
    }
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> u(m), v(m);
    vector<int> deg(n);
    vector<vector<bool>> adj(n, vector<bool>(n));
    vector<vector<int>> id(n, vector<int>(n));
    for (int i = 0, k = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) id[i][j] = k++;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u[i], &v[i]);
        u[i]--, v[i]--;
        ++deg[u[i]];
        adj[u[i]][v[i]] = true;
        adj[v[i]][u[i]] = true;
    }
    int src = n * (n - 1) / 2 + n, snk = n * (n - 1) / 2 + n + 1;
    MinCostFlow<int, int> flow(n * (n - 1) / 2 + n + 2);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (adj[i][j]) continue;
            flow.AddEdge(src, id[i][j], 1, 0);
            flow.AddEdge(id[i][j], i + n * (n - 1) / 2, 1, 0);
            flow.AddEdge(id[i][j], j + n * (n - 1) / 2, 1, 0);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) flow.AddEdge(i + n * (n - 1) / 2, snk, 1, deg[i] + j);
    }
    auto [f, _] = flow(src, snk);
    vector<vector<bool>> ans(n, vector<bool>(n));
    for (int i = 0; i < m; ++i) ans[u[i]][v[i]] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (adj[i][j]) continue;
            int a = flow.GetFlow(id[i][j], i + n * (n - 1) / 2);
            int b = flow.GetFlow(id[i][j], j + n * (n - 1) / 2);
            assert(a + b == 1);
            if (a == 1) ans[i][j] = true;
            else ans[j][i] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (ans[i][j]) printf("1");
            else printf("0");
        }
        puts("");
    }
    return 0;
}