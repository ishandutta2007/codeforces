#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>

template <class Cost = int>
struct Edge {
    int src, dst;
    Edge(int src = -1, int dst = -1)
        : src(src), dst(dst){};
};

template <class Cost = int>
struct Graph {
    std::vector<std::vector<Edge<Cost>>> graph;

    Graph(int n = 0) : graph(n) {}

    void span(bool direct, int src, int dst) {
        graph[src].emplace_back(src, dst);
        if (!direct) graph[dst].emplace_back(dst, src);
    }

    int size() const { return graph.size(); }
    void clear() { graph.clear(); }
    void resize(int n) { graph.resize(n); }

    std::vector<Edge<Cost>>& operator[](int v) { return graph[v]; }
    std::vector<Edge<Cost>> operator[](int v) const { return graph[v]; }
};

constexpr int N = 1000000;

int par[21][N];

template <class Cost = int>
struct LevelAncestor {
    Graph<Cost> tree;
    int kmax;

    void dfs(int v, int p = -1) {
        par[0][v] = p;
        for (const auto& e : tree[v]) {
            if (e.dst == p) continue;
            dfs(e.dst, v);
        }
    }

    LevelAncestor(const Graph<Cost>& tree, int root)
        : tree(tree) {
        kmax = 0;
        while ((1 << kmax) < (int)tree.size()) ++kmax;

        dfs(root);

        for (int k = 1; k <= kmax; ++k) {
            for (int v = 0; v < (int)tree.size(); ++v) {
                int p = par[k - 1][v];
                par[k][v] = (p == -1 ? -1 : par[k - 1][p]);
            }
        }
    }

    int climb(int v, int d) const {
        for (int k = kmax; k >= 0 && v != -1; --k) {
            if ((1 << k) > d) continue;

            v = par[k][v];
            d -= (1 << k);
        }
        return v;
    }
};

void solve() {
    int n, k;
    std::cin >> n >> k;

    Graph<> graph(n);
    for (int v = 1; v < n; ++v) {
        int p;
        std::cin >> p;
        graph.span(true, --p, v);
    }

    std::vector<int> vs;
    {
        std::queue<int> que;
        que.push(0);

        while (!que.empty()) {
            int v = que.front();
            que.pop();
            vs.push_back(v);

            for (auto e : graph[v]) {
                que.push(e.dst);
            }
        }
    }

    auto rvs = vs;
    std::reverse(rvs.begin(), rvs.end());

    std::vector<int> up(n, 0);
    for (auto v : rvs) {
        if (graph[v].empty()) {
            up[v] = k;
            continue;
        }

        for (auto e : graph[v]) {
            up[v] = std::max(up[v], up[e.dst] - 1);
        }
    }

    std::vector<int> upto(n);
    {
        LevelAncestor<> la(graph, 0);

        for (auto v : vs) {
            int u = la.climb(v, up[v]);
            if (u == -1) u = 0;
            upto[v] = (u == v ? u : upto[u]);
        }
    }

    std::vector<int> szs(n, 0);
    for (auto v : vs) {
        if (graph[v].empty()) ++szs[upto[v]];
    }

    for (auto v : rvs) {
        int max = 0;
        for (auto e : graph[v]) max = std::max(max, szs[e.dst]);
        szs[v] += max;
    }

    std::cout << szs[0] << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}