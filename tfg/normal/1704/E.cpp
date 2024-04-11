#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector<int> topologicalOrder(const std::vector<std::vector<int>> &graph) {
    int n = (int) graph.size();
    std::vector<int> deg(n, 0);
    for(int i = 0; i < n; i++) {
        for(auto j : graph[i]) {
            deg[j]++;
        }
    }
    std::vector<int> order;
    for(int i = 0; i < n; i++) {
        if(deg[i] == 0) {
            order.push_back(i);
        }
    }
    for(int i = 0; i < (int) order.size(); i++) {
        int on = order[i];
        for(auto to : graph[on]) {
            if(--deg[to] == 0) {
                order.push_back(to);
            }
        }
    }
    return order;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<int>> graph(n);
        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        while(m--) {
            int u, v;
            std::cin >> u >> v;
            graph[u-1].push_back(v-1);
        }
        auto ord = topologicalOrder(graph);
        int ans = 0;
        const int MOD = 998244353;
        for(int rep = 0; rep < n + 2; rep++) {
            bool good = true;
            for(int i = 0; i < n; i++) {
                good = good && a[i] == 0;
            }
            if(good) {
                break;
            }
            std::vector<int> b(n, 0);
            for(int i = 0; i < n; i++) if(a[i]) {
                b[i] += a[i] - 1;
                for(auto j : graph[i]) {
                    b[j]++;
                }
            }
            for(int i = 0; i < n; i++) {
                a[i] = (int) b[i];
            }
            ans++;
        }
        std::vector<int> dp(n, 0);
        dp[ord.back()] = 1;
        for(int i = n-1; i >= 0; i--) {
            int u = ord[i];
            for(auto v : graph[u]) {
                dp[u] = (dp[u] + dp[v]) % MOD;
            }
        }
        for(int i = 0; i < n; i++) {
            ans = (int) ((ans + (long long) dp[i] * a[i]) % MOD);
        }
        std::cout << ans << '\n';
    }
}