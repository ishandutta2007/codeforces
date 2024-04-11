#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

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

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> szs(3);
    for (auto& sz : szs) std::cin >> sz;

    Graph<> graph(n);
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        graph.span(false, --u, --v);
    }

    std::vector<std::vector<int>> vss;
    {
        std::vector<int> ids(n, -1);

        std::vector<std::vector<int>> tmps(2);
        std::function<void(int)> dfs =
            [&](int v) -> void {
            tmps[ids[v]].push_back(v);
            for (auto e : graph[v]) {
                int u = e.dst;

                if (ids[u] == -1) {
                    ids[u] = 1 - ids[v];
                    dfs(u);
                } else if (ids[u] == ids[v]) {
                    std::cout << "NO\n";
                    std::exit(0);
                }
            }
        };

        for (int v = 0; v < n; ++v) {
            if (ids[v] != -1) continue;
            ids[v] = 0;
            dfs(v);
            for (auto& vs : tmps) {
                vss.push_back(vs);
                vs.clear();
            }
        }
    }

    int k = vss.size() / 2;

    auto dp = vec(k + 1, vec(n + 1, -1));
    dp[0][0] = 0;
    for (int i = 0; i < k * 2; ++i) {
        int sz = vss[i].size();
        for (int j = 0; j + sz <= n; ++j) {
            if (dp[i / 2][j] == -1) continue;
            dp[i / 2 + 1][j + sz] = i;
        }
    }

    if (dp[k][szs[1]] == -1) {
        std::cout << "NO\n";
        return;
    }

    std::cout << "YES\n";
    std::vector<int> ans(n, -1);
    {
        int j = szs[1];
        for (int i = k; i > 0; --i) {
            int id = dp[i][j];
            for (auto v : vss[id]) ans[v] = 2;
            j -= vss[id].size();
        }
    }

    for (int v = 0; v < n; ++v) {
        if (ans[v] != -1) continue;
        if (szs[0] > 0) {
            ans[v] = 1;
            --szs[0];
        } else {
            ans[v] = 3;
        }
    }

    for (auto a : ans) std::cout << a;
    std::cout << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}