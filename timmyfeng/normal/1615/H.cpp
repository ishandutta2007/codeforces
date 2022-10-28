#include <bits/stdc++.h>
using namespace std;

template <class cap_t, class cost_t>
struct min_circulation {
    struct edge {
        int from, to;
        cap_t cap, scaled_cap;
        cost_t cost;
        edge *reverse;
    };

    cost_t reduced_cost(edge *e) {
        return e->cost + potential[e->from] - potential[e->to];
    }

    min_circulation(int n) : n(n) {
        adj.resize(n);
        potential.resize(n);
        dist.resize(n);
        parent.resize(n);
    }

    void add_edge(int from, int to, cap_t cap, cost_t cost) {
        edges.push_back(new edge{from, to, cap, 0, cost, nullptr});
        edge *forward = edges.back();

        edges.push_back(new edge{to, from, 0, 0, -cost, nullptr});
        edge *backward = edges.back();

        forward->reverse = backward;
        backward->reverse = forward;

        adj[from].push_back(forward);
        adj[to].push_back(backward);
    }

    void dijkstra(int src) {
        ranges::fill(dist, numeric_limits<cost_t>::max());
        ranges::fill(parent, nullptr);
        priority_queue<pair<cost_t, int>> closest;

        if (src == -1) {
            for (int i = 0; i < n; ++i) dist[i] = -potential[i], closest.push({-dist[i], i});
        } else {
            dist[src] = 0, closest.push({0, src});
        }

        while (!closest.empty()) {
            auto [d, u] = closest.top(); closest.pop(); d = -d;
            if (d > dist[u]) continue;

            for (auto e : adj[u]) {
                if (e->scaled_cap == 0) continue;
                if (d + reduced_cost(e) < dist[e->to]) {
                    assert(reduced_cost(e) >= 0);
                    dist[e->to] = d + reduced_cost(e);
                    closest.push({-dist[e->to], e->to});
                    parent[e->to] = e;
                }
            }
        }
    }

    void update_potentials(cost_t shift) {
        cost_t max_dist = 0;
        for (int u = 0; u < n; ++u) {
            if (dist[u] < numeric_limits<cost_t>::max()) {
                potential[u] += dist[u];
                max_dist = max(max_dist, dist[u]);
            }
        }

        for (int u = 0; u < n; ++u) {
            if (dist[u] == numeric_limits<cost_t>::max()) {
                potential[u] += max_dist + shift;
            }
        }
    }

    cost_t increase_cap(edge *e) {
        if (e->scaled_cap > 0) {
            ++e->scaled_cap;
            return 0;
        }

        dijkstra(e->to);
        update_potentials(max((cost_t) 0, -reduced_cost(e)));

        cost_t cycle_cost = 0;
        if (reduced_cost(e) < 0) {
            cycle_cost = reduced_cost(e);
            ++e->reverse->scaled_cap;
            for (int u = e->from; u != e->to; u = parent[u]->from) {
                --parent[u]->scaled_cap;
                ++parent[u]->reverse->scaled_cap;
            }
        } else {
            ++e->scaled_cap;
        }

        dijkstra(-1);
        update_potentials(0);

        return cycle_cost;
    }

    cost_t solve() {
        cap_t max_cap = 0;
        for (auto e : edges) {
            max_cap = max(max_cap, e->cap);
            e->scaled_cap = 0;
        }

        cap_t delta = 1;
        while (delta <= max_cap / 2) delta *= 2;

        cost_t objective = 0;
        while (delta > 0) {
            for (auto e : edges) e->scaled_cap *= 2;
            for (auto e : edges) {
                if ((e->cap & delta) > 0) objective += increase_cap(e);
            }
            delta /= 2;
        }
        return objective;
    }

    vector<vector<edge*>> adj;
    vector<edge*> edges;
    int n;

    vector<cost_t> potential, dist;
    vector<edge*> parent;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    min_circulation<int, long long> mcmf(n + 2);
    int src = 0, sink = n + 1;

    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        mcmf.add_edge(src, i, 1, a);
        mcmf.add_edge(i, sink, 1, -a);
    }

    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        mcmf.add_edge(v, u, n, 0);
    }

    mcmf.add_edge(sink, src, n, 0);

    cerr << -mcmf.solve() << "\n";

    for (int i = 1; i <= n; ++i) cout << mcmf.potential[i] - mcmf.potential[src] << " ";
    cout << "\n";
}