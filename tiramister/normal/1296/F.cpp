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
using Graph = std::vector<std::vector<Edge<Cost>>>;

void solve() {
    int n;
    std::cin >> n;

    Graph<int> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        tree[u].emplace_back(u, v, i);
        tree[v].emplace_back(v, u, i);
    }

    int m;
    std::cin >> m;

    std::vector<std::tuple<int, int, int>> qs;
    qs.reserve(m);
    while (m--) {
        int u, v, f;
        std::cin >> u >> v >> f;
        --u, --v;
        qs.emplace_back(f, u, v);
    }
    std::sort(qs.rbegin(), qs.rend());

    std::function<std::vector<int>(int, int, int)> dfs =
        [&](int s, int g, int p = -1) {
            for (auto e : tree[s]) {
                if (e.dst == p) continue;
                if (e.dst == g) {
                    return std::vector<int>({e.cost});
                }
                auto ret = dfs(e.dst, g, s);
                if (!ret.empty()) {
                    ret.push_back(e.cost);
                    return ret;
                }
            }
            return std::vector<int>();
        };

    std::vector<int> ans(n - 1, -1);
    for (auto q : qs) {
        int f, u, v;
        std::tie(f, u, v) = q;
        auto es = dfs(u, v, -1);

        bool ok = false;
        for (auto e : es) {
            if (ans[e] <= f) {
                ok = true;
                ans[e] = f;
            }
        }
        if (!ok) {
            std::cout << -1 << std::endl;
            return;
        }
    }
    for (auto& f : ans) {
        if (f < 0) f = 1000000;
    }

    for (auto f : ans) std::cout << f << " ";
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}