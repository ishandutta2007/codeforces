#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector<long long> dijkstra(const std::vector<std::vector<std::pair<int, int>>> &edges) {
	int n = (int) edges.size();
	std::vector<long long> dist(n, 1e18);
	dist[0] = 0;
	std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> hp;
	hp.push({0, 0});
	while(!hp.empty()) {
		int on = hp.top().second;
		long long curDist = hp.top().first;
		hp.pop();
		if(curDist != dist[on]) continue;
		if(curDist & 1) {
			curDist--;
		}
		for(auto e : edges[on]) {
			long long toDist = curDist + e.second;
			int to = e.first;
			if(dist[to] > toDist) {
				dist[to] = toDist;
				hp.push({toDist, to});
			}
		}
	}
	return dist;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, q;
	std::cin >> n >> m >> q;
	std::vector<std::vector<std::pair<int, int>>> edges(n);
	while(m--) {
		int u, v, c;
		std::cin >> u >> v >> c;
		u--;v--;
		edges[u].emplace_back(v, 2*c);
		edges[v].emplace_back(u, 2*c);
	}
	for(int i = 0; i < q; i++) {
		int x, d;
		std::cin >> x >> d;
		x--;
		edges[0].emplace_back(x, 2*d + 1);
	}
	auto dist = dijkstra(edges);
	int ans = q;
	for(auto &d : dist) {
		ans -= d & 1;
	}
	std::cout << ans << '\n';
}