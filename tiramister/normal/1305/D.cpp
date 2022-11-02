#include <iostream>
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

int query(int u, int v) {
    std::cout << "? " << u + 1 << " " << v + 1 << std::endl;
    int w;
    std::cin >> w;
    return w - 1;
}

int answer(int v) {
    std::cout << "! " << v + 1 << std::endl;
    std::exit(0);
}

void solve() {
    int n;
    std::cin >> n;

    Graph<> tree(n);
    std::vector<int> deg(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        tree[u].emplace_back(u, v);
        tree[v].emplace_back(v, u);
        ++deg[u], ++deg[v];
    }

    std::queue<int> que;
    for (int v = 0; v < n; ++v) {
        if (deg[v] == 1) que.push(v);
    }

    while (que.size() >= 2) {
        int u = que.front();
        que.pop();
        int v = que.front();
        que.pop();

        int w = query(u, v);
        if (u == w || v == w) answer(w);

        for (auto e : tree[u]) {
            if (--deg[e.dst] == 1) que.push(e.dst);
        }
        for (auto e : tree[v]) {
            if (--deg[e.dst] == 1) que.push(e.dst);
        }
    }

    int r = que.front();
    answer(r);
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}