#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> edges(n);
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(i - a[i] >= 0) {
			edges[i - a[i]].push_back(i);
		}
		if(i + a[i] < n) {
			edges[i + a[i]].push_back(i);
		}
	}
	const int INF = 1e9;
	std::vector<int> ans(n, INF);
	for(int rep = 0; rep < 2; rep++) {
		std::vector<int> dist(n, INF);
		std::queue<int> q;
		for(int i = 0; i < n; i++) {
			if(a[i] % 2 == rep) {
				dist[i] = 0;
				q.push(i);
			}
		}
		while(!q.empty()) {
			int on = q.front();
			q.pop();
			for(auto to : edges[on]) {
				if(dist[to] > 1 + dist[on]) {
					dist[to] = 1 + dist[on];
					q.push(to);
				}
			}
		}
		for(int i = 0; i < n; i++) {
			if(a[i] % 2 != rep) {
				ans[i] = dist[i] == INF ? -1 : dist[i];
			}
		}
	}
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
	}
}