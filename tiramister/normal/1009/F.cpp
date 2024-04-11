#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

std::vector<std::vector<int>> graph;
std::vector<int> ans;

std::vector<int> dfs(int v, int p) {
    auto& dom = ans[v];

    std::vector<int> dp{1};
    dom = 0;

    for (auto u : graph[v]) {
        if (u == p) continue;

        auto ndp = dfs(u, v);
        ndp.push_back(0);

        if (dp.size() < ndp.size()) {
            dom = ans[u] + 1;
            std::swap(dp, ndp);
        }

        int n = dp.size();
        int m = ndp.size();

        for (int i = 0; i < m; ++i) {
            dp[n - i - 1] += ndp[m - i - 1];
            if ((dp[n - i - 1] > dp[n - dom - 1]) ||
                (dp[n - i - 1] == dp[n - dom - 1] && i < dom)) dom = i;
        }
    }

    return dp;
}

void solve() {
    int n;
    std::cin >> n;

    graph.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ans.assign(n, -1);
    dfs(0, -1);

    for (auto a : ans) std::cout << a << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}