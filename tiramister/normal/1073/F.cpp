#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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

void solve() {
    int n;
    std::cin >> n;

    Graph<> graph(n * 2 - 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        graph.span(false, --u, n + i);
        graph.span(false, --v, n + i);
    }

    n = n * 2 - 1;
    std::vector<std::vector<std::pair<int, int>>> leaves(n);
    std::vector<bool> removed(n, false);

    {
        std::queue<int> que;
        for (int v = 0; v < n; ++v) {
            if ((int)graph[v].size() > 1) continue;

            que.push(v);
            leaves[v].emplace_back(0, v);
        }

        while (!que.empty()) {
            int v = que.front();
            que.pop();
            if ((int)graph[v].size() > 2) continue;

            removed[v] = true;

            auto p = leaves[v].front();
            ++p.first;

            for (auto e : graph[v]) {
                int u = e.dst;
                if (removed[u]) continue;

                leaves[u].push_back(p);
                que.push(u);
            }
        }

        for (int v = 0; v < n; ++v) {
            std::sort(leaves[v].rbegin(), leaves[v].rend());
        }
    }

    // find center
    int c, rad;
    {
        auto bfs = [&](int r) {
            std::vector<int> dist(n, -1), rev(n, -1);
            dist[r] = 0;

            std::queue<int> que;
            que.push(r);

            while (!que.empty()) {
                int v = que.front();
                que.pop();

                for (auto e : graph[v]) {
                    int u = e.dst;
                    if (removed[u] || dist[u] != -1) continue;
                    dist[u] = dist[v] + 1;
                    rev[u] = v;
                    que.push(u);
                }
            }

            return std::make_pair(dist, rev);
        };

        int r = 0;
        while (removed[r]) ++r;

        {
            auto dist = bfs(r).first;
            r = std::max_element(dist.begin(), dist.end()) - dist.begin();
        }

        {
            auto [dist, rev] = bfs(r);
            rad = *std::max_element(dist.begin(), dist.end()) / 2;

            c = std::max_element(dist.begin(), dist.end()) - dist.begin();
            for (int i = 0; i < rad; ++i) c = rev[c];
        }
    }

    std::vector<int> vs;
    {
        std::vector<int> ws;
        std::function<void(int, int, int)> dfs =
            [&](int v, int p, int d) -> void {
            if (d == rad) {
                ws.push_back(v);
                return;
            }

            for (auto e : graph[v]) {
                int u = e.dst;
                if (u == p || removed[u]) continue;
                dfs(u, v, d + 1);
            }
        };

        for (auto e : graph[c]) {
            int nv = e.dst;
            if (removed[nv]) continue;

            ws.clear();
            dfs(nv, c, 1);
            if (ws.empty()) continue;

            std::sort(ws.begin(), ws.end(),
                      [&](int u, int v) {
                          return leaves[u][0].first + leaves[u][1].first >
                                 leaves[v][0].first + leaves[v][1].first;
                      });
            vs.push_back(ws.front());
        }
    }

    std::sort(vs.begin(), vs.end(),
              [&](int u, int v) {
                  return leaves[u][0].first + leaves[u][1].first >
                         leaves[v][0].first + leaves[v][1].first;
              });

    for (int j = 0; j < 2; ++j) {
        for (int i = 0; i < 2; ++i) {
            std::cout << leaves[vs[i]][j].second + 1 << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}