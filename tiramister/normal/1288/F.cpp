#include <iostream>
#include <vector>
#include <limits>

template <class Cap, class Cost>
struct MinCostFlow {
    struct Edge {
        int src, dst;
        Cap cap;
        Cost cost;
        int id;
        Edge(int src, int dst, Cap cap, Cost cost, int id)
            : src(src), dst(dst), cap(cap), cost(cost), id(id){};
    };

    using Edges = std::vector<Edge>;
    using Graph = std::vector<std::vector<int>>;

    Edges edges;
    Graph graph;
    std::vector<Cost> dist;
    std::vector<int> rev;
    bool flowed;

    const Cost INF = std::numeric_limits<Cost>::max() / 2;

    explicit MinCostFlow(int n)
        : graph(n), dist(n), rev(n), flowed(false) {}

    void span(int u, int v, Cap cap, Cost cost, int id) {
        graph[u].push_back(edges.size());
        edges.emplace_back(u, v, cap, cost, id);

        graph[v].push_back(edges.size());
        edges.emplace_back(v, u, 0, -cost, -1);
    }

    void bellman_ford(int s) {
        std::fill(dist.begin(), dist.end(), INF);
        dist[s] = 0;

        for (int i = 0; i < (int)graph.size(); ++i) {
            for (int eidx = 0; eidx < (int)edges.size(); ++eidx) {
                const auto& edge = edges[eidx];
                int u = edge.src, v = edge.dst;

                if (edge.cap > 0 &&
                    dist[u] < INF &&
                    dist[v] > dist[u] + edge.cost) {
                    dist[v] = dist[u] + edge.cost;
                    rev[v] = eidx;
                }
            }
        }
    }

    Cost exec(int s, int g, Cap flow) {
        Cost ret = 0;

        while (flow > 0) {
            bellman_ford(s);
            if (dist[g] == INF) break;

            Cap f = flow;
            int v = g;
            while (v != s) {
                const auto& edge = edges[rev[v]];
                f = std::min(f, edge.cap);
                v = edge.src;
            }

            flow -= f;
            ret += f * dist[g];

            v = g;
            while (v != s) {
                auto& edge = edges[rev[v]];
                auto& redge = edges[rev[v] ^ 1];
                edge.cap -= f;
                redge.cap += f;
                v = edge.src;
            }
        }
        flowed = (flow == 0);
        return ret;
    }
};

using lint = long long;
constexpr lint INF = 1LL << 30;

void solve() {
    int n1, n2, m;
    lint r, b;
    std::cin >> n1 >> n2 >> m >> r >> b;

    const int s = n1 + n2, g = n1 + n2 + 1;
    MinCostFlow<lint, lint> mcf(n1 + n2 + 2);

    lint buf = 0;
    for (int v = 0; v < n1 + n2; ++v) {
        char c;
        std::cin >> c;

        if (c == 'U') {
            mcf.span(s, v, INF, 0, -1);
            mcf.span(v, g, INF, 0, -1);
            continue;
        }

        buf += INF;
        if ((c == 'R') == (v < n1)) {
            mcf.span(s, v, 1, -INF, -1);
            mcf.span(s, v, INF, 0, -1);
        } else {
            mcf.span(v, g, 1, -INF, -1);
            mcf.span(v, g, INF, 0, -1);
        }
    }
    mcf.span(s, g, INF, 0, -1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;

        mcf.span(u, v + n1, 1, r, i);
        mcf.span(v + n1, u, 1, b, i);
    }

    auto cost = mcf.exec(s, g, n1 + n2) + buf;
    if (!mcf.flowed || cost >= INF) {
        std::cout << -1 << std::endl;
        return;
    }

    std::string ass(m, 'U');
    for (auto e : mcf.edges) {
        if (e.id == -1 || e.cap > 0) continue;

        int u = e.src, v = e.dst, id = e.id;
        ass[id] = (u < v ? 'R' : 'B');
    }

    std::cout << cost << std::endl
              << ass << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}