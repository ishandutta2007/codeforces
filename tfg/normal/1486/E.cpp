#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstring>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

int dist[ms][51];
std::vector<std::pair<int, int>> edges[ms];

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    memset(dist, 0x3f, sizeof dist);
    int n, m;
    std::cin >> n >> m;
    while(m--) {
        int u, v, d;
        std::cin >> u >> v >> d;
        u--;v--;
        edges[u].emplace_back(v, d);
        edges[v].emplace_back(u, d);
    }
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> hp;
    hp.push({0, 0});
    dist[0][0] = 0;
    while(!hp.empty()) {
        int onTemp = hp.top().second / n;
        int on = hp.top().second % n;
        int onDist = hp.top().first;
        hp.pop();
        if(onDist != dist[on][onTemp]) continue;
        for(auto [to, cost] : edges[on]) {
            int toTemp, toDist;
            if(onTemp == 0) {
                toTemp = cost, toDist = onDist;
            } else {
                cost += onTemp;
                toTemp = 0, toDist = onDist + cost * cost;
            }
            if(toDist < dist[to][toTemp]) {
                dist[to][toTemp] = toDist;
                hp.push({toDist, to + toTemp * n});
            }
        }
    }
    const int INF = 0x3f3f3f3f;
    for(int i = 0; i < n; i++) {
        std::cout << (dist[i][0] == INF ? -1 : dist[i][0]) << (i + 1 == n ? '\n' : ' ');
    }
}