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
using Edges = std::vector<Edge<Cost>>;

template <class Cost = int>
using Graph = std::vector<std::vector<Edge<Cost>>>;

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    Graph<> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        tree[u].emplace_back(u, v);
        tree[v].emplace_back(v, u);
    }

    std::vector<std::pair<int, int>> ans(n);
    int cur = 2;

    std::function<void(int, int)>
        dfs = [&](int v, int p) {
            int t = cur;

            int sz = tree[v].size();
            if (p >= 0) --sz;

            int id = t + sz - 1;
            cur += sz;
            ans[v].second = cur++;

            for (auto e : tree[v]) {
                int u = e.dst;
                if (u == p) continue;
                ans[u].first = id--;
                dfs(u, v);
            }
        };
    ans[0].first = 1;
    dfs(0, -1);

    for (auto p : ans) {
        std::cout << p.first << " " << p.second << "\n";
    }
    return 0;
}