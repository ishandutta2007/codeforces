#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> hp;
    std::vector<int> dist(n, 1e8);
    dist[n-1] = 0;
    hp.push({0, n-1});
    std::vector<int> rem(n, 0);
    std::vector<std::vector<int>> edges(n);
    while(m--) {
        int u, v;
        std::cin >> u >> v;
        u--;v--;
        rem[u]++;
        edges[v].emplace_back(u);
    }
    while(!hp.empty()) {
        auto [curDist, on] = hp.top();
        hp.pop();
        if(curDist != dist[on]) continue;
        for(auto to : edges[on]) {
            rem[to]--;
            int toDist = curDist + rem[to] + 1;
            if(toDist < dist[to]) {
                dist[to] = toDist;
                hp.push({toDist, to});
            }
        }
    }
    std::cout << dist[0] << '\n';
}