#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template<class T>
using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

std::vector<long long> dijkstra(const std::vector<std::vector<std::pair<int, long long>>> &edges, int st) {
	std::vector<long long> dist(edges.size(), 1e18);
	dist[st] = 0;
	min_heap<std::pair<long long, int>> hp;
	hp.push({0, 0});
	while(!hp.empty()) {
		long long onDist = hp.top().first;
		int on = hp.top().second;
		hp.pop();
		if(onDist != dist[on]) { continue; }
		for(auto e : edges[on]) {
			long long toDist = onDist + e.second;
			int to = e.first;
			if(toDist < dist[to]) {
				dist[to] = toDist;
				hp.push({toDist, to});
			}
		}
	}
	return dist;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<std::pair<int, long long>>> edges(4*n);
	while(m--) {
		int u, v, w;
		std::cin >> u >> v >> w;
		u--;v--;
		for(int rep = 0; rep < 2; rep++) {
			for(int mask = 0; mask < 4; mask++) {
				edges[4*u+mask].emplace_back(4*v+mask, w);
				if(!(mask&1)) {
					edges[4*u+mask].emplace_back(4*v+mask+1, 0);
				}
				if(!(mask&2)) {
					edges[4*u+mask].emplace_back(4*v+mask+2, 2*w);
				}
			}
			std::swap(u, v);
		}
	}
	auto dist = dijkstra(edges, 0);
	for(int i = 1; i < n; i++) {
		std::cout << std::min(dist[4*(i+1)-1], dist[4*i]) << (i + 1 == n ? '\n' : ' ');
	}
}