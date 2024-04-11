#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

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
using Graph = std::vector<std::vector<Edge<Cost>>>;

template <class Cost = int>
struct StronglyConnectedComponents {
    Graph<Cost> graph, rgraph;
    std::vector<bool> visited;
    std::vector<int> stk;

    // id[v] = vgroups[id[v]]
    std::vector<int> id;
    std::vector<std::vector<int>> groups;

    explicit StronglyConnectedComponents(const Graph<Cost>& g)
        : graph(g), visited(graph.size(), false), id(graph.size(), -1) {
        revinit();

        for (int v = 0; v < (int)graph.size(); ++v) dfs(v);

        while (!stk.empty()) {
            int v = stk.back();
            stk.pop_back();
            if (id[v] < 0) {
                groups.emplace_back();
                rdfs(v);
            }
        }
    }

    void revinit() {
        rgraph = Graph<Cost>(graph.size());
        for (int v = 0; v < (int)graph.size(); ++v) {
            for (const auto& e : graph[v]) {
                rgraph[e.dst].emplace_back(e.dst, v, e.cost);
            }
        }
    }

    void dfs(int v) {
        if (visited[v]) return;
        visited[v] = true;
        for (const auto& e : graph[v]) dfs(e.dst);
        stk.push_back(v);
    }

    void rdfs(int v) {
        if (id[v] >= 0) return;
        id[v] = groups.size() - 1;
        groups.back().push_back(v);
        for (const auto& e : rgraph[v]) rdfs(e.dst);
    }
};

std::vector<int> bfs(const Graph<>& graph, std::vector<int> ss) {
    std::vector<int> from(graph.size() * 2, -2);
    std::queue<int> que;
    for (auto s : ss) {
        from[s] = -1;
        que.push(s);
    }

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto e : graph[v]) {
            int u = e.dst;
            if (from[u] != -2) continue;

            from[u] = v;
            que.push(u);
        }
    }
    return from;
}

void solve() {
    int n, m;
    std::cin >> n >> m;

    Graph<> graph(n), bgraph(n * 2);
    std::vector<bool> leaf(n, false);
    for (int u = 0; u < n; ++u) {
        int d;
        std::cin >> d;
        if (d == 0) leaf[u] = true;

        while (d--) {
            int v;
            std::cin >> v;
            --v;

            graph[u].emplace_back(u, v);
            bgraph[u].emplace_back(u, v + n);
            bgraph[u + n].emplace_back(u + n, v);
        }
    }

    int s;
    std::cin >> s;
    --s;

    auto bfrom = bfs(bgraph, {s});
    for (int v = 0; v < n; ++v) {
        if (!leaf[v] || bfrom[v + n] == -2) continue;

        std::cout << "Win" << std::endl;
        std::vector<int> ans{v};

        v += n;
        while (bfrom[v] != -1) {
            v = bfrom[v];
            ans.push_back(v % n);
        }
        std::reverse(ans.begin(), ans.end());

        for (auto u : ans) std::cout << u + 1 << " ";
        std::cout << std::endl;
        return;
    }

    StronglyConnectedComponents<> scc(graph);

    for (int v = 0; v < n; ++v) {
        if (bfrom[v] == -2 && bfrom[v + n] == -2) continue;
        if (scc.groups[scc.id[v]].size() == 1) continue;

        std::cout << "Draw" << std::endl;
        return;
    }

    std::cout << "Lose" << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}