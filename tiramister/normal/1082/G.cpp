#include <iostream>
#include <vector>
#include <queue>
#include <limits>

template <class Cap, bool isDirect>
struct MaxFlow {
    struct Edge {
        int src, dst;
        Cap cap;
        Edge(int src, int dst, Cap cap)
            : src(src), dst(dst), cap(cap){};
    };

    using Edges = std::vector<Edge>;
    using Graph = std::vector<std::vector<int>>;

    Edges edges;
    Graph graph;
    std::vector<int> dist, iter;

    explicit MaxFlow(int n)
        : graph(n), dist(n), iter(n) {}

    void span(int u, int v, Cap cap) {
        graph[u].push_back(edges.size());
        edges.emplace_back(u, v, cap);

        graph[v].push_back(edges.size());
        edges.emplace_back(v, u, (isDirect ? 0 : cap));
    }

    void bfs(int s) {
        std::fill(dist.begin(), dist.end(), -1);
        dist[s] = 0;
        std::queue<int> que;
        que.push(s);

        while (!que.empty()) {
            int v = que.front();
            que.pop();

            for (int eidx : graph[v]) {
                const auto& edge = edges[eidx];

                if (edge.cap > 0 && dist[edge.dst] < 0) {
                    dist[edge.dst] = dist[v] + 1;
                    que.push(edge.dst);
                }
            }
        }
    }

    int dfs(int v, int g, Cap f) {
        if (v == g) return f;

        for (int& itr = iter[v]; itr < (int)graph[v].size(); ++itr) {
            int eidx = graph[v][itr];
            auto& edge = edges[eidx];

            if (edge.cap > 0 && dist[v] < dist[edge.dst]) {
                Cap df = dfs(edge.dst, g, std::min(f, edge.cap));

                if (df > 0) {
                    edge.cap -= df;
                    auto& redge = edges[eidx ^ 1];
                    redge.cap += df;
                    return df;
                }
            }
        }
        return 0;
    }

    Cap exec(int s, int g) {
        const Cap INF = std::numeric_limits<Cap>::max();

        Cap ret = 0;
        while (true) {
            bfs(s);
            if (dist[g] < 0) return ret;

            std::fill(iter.begin(), iter.end(), 0);
            while (true) {
                Cap flow = dfs(s, g, INF);
                if (flow == 0) break;
                ret += flow;
            }
        }
    }
};

using lint = long long;
constexpr lint INF = 1LL << 50;

void solve() {
    int n, m;
    std::cin >> n >> m;

    const int s = n + m, g = n + m + 1;
    MaxFlow<lint, true> mf(n + m + 2);

    for (int i = 0; i < n; ++i) {
        lint x;
        std::cin >> x;
        mf.span(m + i, g, x);
    }

    lint buf = 0;
    for (int i = 0; i < m; ++i) {
        int u, v;
        lint x;
        std::cin >> u >> v >> x;
        --u, --v;

        buf += x;
        mf.span(i, m + u, INF);
        mf.span(i, m + v, INF);
        mf.span(s, i, x);
    }

    std::cout << buf - mf.exec(s, g) << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}