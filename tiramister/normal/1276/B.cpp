#include <iostream>
#include <vector>
#include <functional>

template <class Cost = int>
struct Edge {
    int src, dst;
    Cost cost;
    Edge(int src = -1, int dst = -1, Cost cost = 1)
        : src(src), dst(dst), cost(cost){};

    bool operator<(const Edge<Cost>& e) const { return this->cost < e.cost; }
    bool operator>(const Edge<Cost>& e) const { return this->cost > e.cost; }
};

template <class Cost = int>
struct Graph {
    std::vector<std::vector<Edge<Cost>>> graph;

    Graph(int n = 0) : graph(n) {}

    void span(bool direct, int src, int dst, Cost cost = 1) {
        graph[src].emplace_back(src, dst, cost);
        if (!direct) graph[dst].emplace_back(dst, src, cost);
    }

    int size() const { return graph.size(); }
    void clear() { graph.clear(); }
    void resize(int n) { graph.resize(n); }

    std::vector<Edge<Cost>>& operator[](int v) { return graph[v]; }
    std::vector<Edge<Cost>> operator[](int v) const { return graph[v]; }
};

template <class Cost = int>
struct Lowlink {
    Graph<Cost> graph;
    int time;
    std::vector<int> order, low;

    std::vector<int> artics;
    std::vector<Edge<Cost>> bridges;

    explicit Lowlink(const Graph<Cost>& graph)
        : graph(graph), order(graph.size(), -1), low(graph.size(), graph.size()) {
        time = 0;
        for (int v = 0; v < (int)graph.size(); ++v) {
            if (order[v] < 0) dfs(v, -1);
        }
    }

    void dfs(int v, int r) {
        order[v] = low[v] = time++;
        int deg = 0;
        bool is_artic = false;

        for (auto e : graph[v]) {
            if (order[e.dst] < 0) {
                ++deg;
                dfs(e.dst, e.src);
                low[e.src] = std::min(low[e.src], low[e.dst]);

                if (order[e.src] <= low[e.dst]) is_artic = true;
                if (order[e.src] < low[e.dst]) bridges.push_back(e);
            } else if (e.dst != r) {
                low[e.src] = std::min(low[e.src], order[e.dst]);
            }
        }

        if (r < 0) is_artic = (deg > 1);
        if (is_artic) artics.push_back(v);
    }
};

using lint = long long;

void solve() {
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    --s, --t;

    Graph<> graph(n);
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        graph.span(false, u, v);
    }

    {
        Lowlink<> ll(graph);
        int cnt = 0;
        for (auto v : ll.artics) {
            if (v == s || v == t) ++cnt;
        }

        if (cnt < 2) {
            std::cout << 0 << "\n";
            return;
        }
    }

    std::vector<int> visited(n, -1);
    int r, w;
    std::function<lint(int)>
        dfs = [&](int v) -> lint {
        if (v == w) return -1;

        visited[v] = 1;
        lint ret = 1;
        for (auto e : graph[v]) {
            int u = e.dst;
            if (visited[u] == 1) continue;

            if (visited[u] == 0) {
                if (v != r) {
                    visited[v] = 0;
                    return -1;
                }

            } else {
                auto c = dfs(u);
                if (c == -1) {
                    if (v != r) {
                        visited[v] = 0;
                        return -1;
                    }

                } else {
                    ret += c;
                }
            }
        }
        return ret;
    };

    r = s, w = t;
    auto scnt = dfs(r) - 1;

    std::fill(visited.begin(), visited.end(), -1);
    r = t, w = s;
    auto tcnt = dfs(r) - 1;

    std::cout << scnt * tcnt << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}