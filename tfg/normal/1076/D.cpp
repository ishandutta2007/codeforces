#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 300300;

struct Edge {
	long long c;
	int id, to;

	Edge(int a, long long b, int i) {
		to = a;
		c = b;
		id = i;
	}
};

std::vector<Edge> edges[ms];
long long dist[ms];
int from[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<int> ans;
	for(int i = 1; i <= m; i++) {
		int u, v, c;
		std::cin >> u >> v >> c;
		u--;v--;
		edges[u].emplace_back(v, c, i);
		edges[v].emplace_back(u, c, i);
	}
	// do dijkstra
	for(int i = 1; i < n; i++) {
		dist[i] = (long long) 1e18;
	}
	from[0] = -1;
	std::priority_queue<std::pair<long long, int>> hp;
	hp.push({0, 0});
	while(!hp.empty()) {
		long long curDist = -hp.top().first;
		int on = hp.top().second;
		hp.pop();
		if(curDist != dist[on]) {
			continue;
		}
		//std::cout << "got to " << on << " with dist " << curDist << '\n';
		if(from[on] != -1 && (int) ans.size() < k) {
			ans.push_back(from[on]);
		}
		for(auto e : edges[on]) {
			//std::cout << "edge (" << e.to << ", " << e.c << ", " << e.id << ")\n";
			long long toDist = curDist + e.c;
			if(toDist < dist[e.to]) {
				dist[e.to] = toDist;
				hp.push({-toDist, e.to});
				from[e.to] = e.id;
			}
		}
	}
	// print ans
	std::cout << ans.size() << '\n';
	for(int i = 0; i < (int) ans.size(); i++) {
		std::cout << ans[i] << (i + 1 == (int) ans.size() ? '\n' : ' ');
	}
}