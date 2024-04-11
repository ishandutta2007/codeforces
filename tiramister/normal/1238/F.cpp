#include <iostream>
#include <algorithm>
#include <vector>

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

    std::vector<Edge<Cost>>& operator[](int v) { return graph[v]; }
    std::vector<Edge<Cost>> operator[](int v) const { return graph[v]; }

    void resize(int n) { graph.resize(n); }
    void clear() { graph.clear(); }
    int size() const { return graph.size(); }
};

int ans;
Graph<> tree;

int dfs(int v, int p = -1) {
    std::vector<int> ch{0, 0};

    for (auto e : tree[v]) {
        int u = e.dst;
        if (u == p) continue;
        ch.push_back(dfs(u, v));
    }

    std::sort(ch.rbegin(), ch.rend());
    int cnum = (int)ch.size() - 2;

    ans = std::max(ans, ch[0] + ch[1] + std::max(0, cnum - 2) + 1 + (p != -1));

    int ret = ch[0] + std::max(cnum - 1, 0) + 1;
    return ret;
}

void solve() {
    int n;
    std::cin >> n;

    tree.clear();
    tree.resize(n);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        tree.span(false, --u, --v);
    }

    ans = 0;
    dfs(0);
    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}