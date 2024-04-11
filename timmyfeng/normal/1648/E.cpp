#include <bits/stdc++.h>
using namespace std;

struct edge { int from, to, cost; };

struct min_spanning_tree {
    min_spanning_tree(int n) : n(n) {}

    int find(int u) {
        if (!dsu[u]) return u;
        int temp = find(dsu[u]);
        depth[u] += depth[dsu[u]];
        return dsu[u] = temp;
    }

    void kruskals() {
        sort(edges.begin(), edges.end(), [&](edge a, edge b) { return a.cost < b.cost; });

        tour_prev.resize(2 * n), tour_next.resize(2 * n);
        dsu.resize(2 * n), cost.resize(2 * n);
        head.resize(2 * n), tail.resize(2 * n);

        parent.assign(__lg(2 * n) + 1, vector<int>(2 * n));
        depth.assign(2 * n, 0);

        for (int i = 1; i <= n; ++i) {
            head[i] = tail[i] = i;
        }

        int node_id = n + 1;
        for (auto e : edges) {
            int u = find(e.from), v = find(e.to);
            if (u == v) continue;

            cost[node_id] = e.cost;
            dsu[u] = dsu[v] = parent[0][u] = parent[0][v] = node_id;
            depth[u] = depth[v] = 1;

            head[node_id] = head[u], tail[node_id] = tail[v];
            tour_prev[head[v]] = tail[u], tour_next[tail[u]] = head[v];

            ++node_id;
        }

        for (int i = 1; i < 2 * n; ++i) find(i);

        for (int i = 1; i <= __lg(2 * n); ++i)
            for (int j = 1; j < 2 * n; ++j)
                parent[i][j] = parent[i - 1][parent[i - 1][j]];
    }

    int dist(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);

        for (int i = __lg(2 * n); i >= 0; --i)
            if (depth[v] - depth[u] >= (1 << i))
                v = parent[i][v];

        for (int i = __lg(2 * n); i >= 0; --i)
            if (parent[i][u] != parent[i][v])
                u = parent[i][u], v = parent[i][v];

        return cost[parent[0][u]];
    }

    vector<int> tour_prev, tour_next;
    vector<int> dsu, cost, head, tail;

    vector<vector<int>> parent;
    vector<int> depth;

    vector<edge> edges;
    int n;
};

void solve() {
    int n, m; cin >> n >> m;

    set<pair<int, int>> edge_table;
    vector<edge> edges(m);
    vector<int> degree(n + 1);

    for (auto &e : edges) {
        cin >> e.from >> e.to >> e.cost;
        degree[e.from]++, degree[e.to]++;
        edge_table.insert({e.from, e.to});
        edge_table.insert({e.to, e.from});
    }

    min_spanning_tree graph1(n), graph2(n);
    graph1.edges = edges;
    graph1.kruskals();

    for (int i = 1; i <= n; ++i) {
        int forwards = i, backwards = i;
        for (int j = 0; j < 2 * degree[i] + 1; ++j) {
            forwards = graph1.tour_next[forwards];
            backwards = graph1.tour_prev[backwards];

            for (auto k : {forwards, backwards})
                if (k && !edge_table.count({i, k}))
                    graph2.edges.push_back({i, k, graph1.dist(i, k)});
        }
    }

    graph2.kruskals();

    for (auto e : edges) cout << graph2.dist(e.from, e.to) << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}