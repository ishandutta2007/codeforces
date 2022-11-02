#include <iostream>
#include <algorithm>
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

    std::vector<int> cs(n);
    for (auto& c : cs) std::cin >> c;

    Graph<> graph(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        graph[u].emplace_back(u, v);
        graph[v].emplace_back(v, u);
    }

    std::vector<int> dp(n, -n);
    std::function<int(int, int)>
        dfs = [&](int v, int p) {
            auto& d = dp[v];
            d = (cs[v] ? 1 : -1);

            for (auto e : graph[v]) {
                if (e.dst == p) continue;
                d += std::max(0, dfs(e.dst, v));
            }
            return d;
        };
    dfs(0, -1);

    std::vector<int> ans(n, -n);
    std::function<void(int, int, int)>
        efs = [&](int v, int p, int par) {
            ans[v] = dp[v];
            if (par > 0) ans[v] += par;

            for (auto e : graph[v]) {
                if (e.dst == p) continue;
                int d = dp[v];
                if (par > 0) d += par;
                if (dp[e.dst] > 0) d -= dp[e.dst];
                efs(e.dst, v, d);
            }
        };
    efs(0, -1, 0);

    for (auto a : ans) std::cout << a << " ";
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}