#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> edges(n);
	while(m--) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[v].push_back(u);
	}
	int k;
	std::cin >> k;
	std::vector<int> path(k);
	for(int i = 0; i < k; i++) {
		std::cin >> path[i];
		path[i]--;
	}
	std::vector<int> dist(n, n + 10);
	dist[path.back()] = 0;
	std::queue<int> q;
	q.push(path.back());
	std::vector<int> cnt(n, 0);
	while(!q.empty()) {
		int on = q.front();
		q.pop();
		for(auto to : edges[on]) {
			if(dist[to] > 1 + dist[on]) {
				dist[to] = 1 + dist[on];
				q.push(to);
			}
			if(dist[to] == 1 + dist[on]) {
				cnt[to]++;
			}
		}
	}
	int mn = 0, mx = 0;
	for(int i = 0; i + 1 < k; i++) {
		int u = path[i], v = path[i+1];
		if(dist[v] != dist[u] - 1) {
			mn++;
			mx++;
		} else if(cnt[u] > 1) {
			mx++;
		}
	}
	std::cout << mn << ' ' << mx << '\n';
}