#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, s;
	std::cin >> n >> m >> s;
	s--;
	std::vector<std::vector<std::pair<int, int>>> edges(n);
	while(m--) {
		int u, v, c;
		std::cin >> u >> v >> c;
		u--;v--;
		edges[u].emplace_back(v, c);
		edges[v].emplace_back(u, c);
	}
	int INF;
	std::cin >> INF;
	std::vector<int> dist(n, 1.1e9);
	dist[s] = 0;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> hp;
	hp.push({0, s});
	while(!hp.empty()) {
		auto cur = hp.top();
		hp.pop();
		if(dist[cur.second] != cur.first) continue;
		for(auto e : edges[cur.second]) {
			int to = e.first;
			int toDist = cur.first + e.second;
			if(toDist < dist[to]) {
				dist[to] = toDist;
				hp.push({toDist, to});
			}
		}
	}
	int ans = 0;
	for(auto x : dist) if(x == INF) ans++;
	for(int i = 0; i < n; i++) {
		if(dist[i] >= INF) continue;
		for(auto e : edges[i]) {
			int where = INF - dist[i];
			if(e.second <= where) continue;
			if(INF < dist[e.first] + e.second - where) {
				ans++;
			} else if(INF == dist[e.first] + e.second - where && i < e.first) {
				ans++;
			}
		}
	}
	std::cout << ans << '\n';
}