#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;
const int cost[4] = {0, 2, 1, 1};

std::vector<int> edges[ms];
int val[ms], ans;

int dfs(int on, int par) {
    int curVal = val[on];
    for(auto to : edges[on]) if(to != par) {
        int edgeVal = dfs(to, on);
        ans += cost[edgeVal];
        curVal |= edgeVal;
    }
    return curVal;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        int n, k;
        std::cin >> n >> k;
        ans = 0;
        int x, y;
        std::cin >> x >> y;
        x--;y--;
        val[y] |= 2;
        while(k--) {
            int u;
            std::cin >> u;
            val[u-1] |= 1;
        }
        for(int i = 1; i < n; i++) {
            int u, v;
            std::cin >> u >> v;
            u--;v--;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        dfs(x, x);
        std::cout << ans << '\n';
        for(int i = 0; i < n; i++) {
            edges[i].clear();
            val[i] = 0;
        }
    }
}