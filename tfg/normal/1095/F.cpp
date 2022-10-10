#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const long long INF = 1e18;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<long long> a(n);
	int low = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(a[i] < a[low]) low = i;
	}
	std::vector<std::vector<std::pair<long long, int>>> edges(n);
	std::vector<long long> dist(n, INF);
	for(int i = 0; i < n; i++) {
		edges[low].emplace_back(a[i] + a[low], i);
	}
	while(m--) {
		int u, v;
		long long c;
		std::cin >> u >> v >> c;
		u--;v--;
		edges[u].emplace_back(c, v);
		edges[v].emplace_back(c, u);
	}
	std::priority_queue<std::pair<long long, int>> hp;
	dist[low] = 0;
	hp.push({0, low});
	std::vector<bool> visit(n, false);
	while(!hp.empty()) {
		int on = hp.top().second;
		hp.pop();
		if(visit[on]) continue;
		visit[on] = true;
		for(auto e : edges[on]) {
			int to = e.second;
			if(!visit[to] && dist[to] > e.first) {
				dist[to] = e.first;
				hp.push({-e.first, to});
			}
		}
	}
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		ans += dist[i];
	}
	std::cout << ans << '\n';
}