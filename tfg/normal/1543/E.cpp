#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::vector<std::vector<int>> edges(1 << n);
		for(int i = 0; i < (1 << n) * n / 2; i++) {
			int u, v;
			std::cin >> u >> v;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		std::vector<int> dist(1 << n, 1e9), rep(1 << n, 0);
		dist[0] = 0;
		std::queue<int> q;
		for(int i = 0; i < n; i++) {
			dist[edges[0][i]] = 1, rep[edges[0][i]] = 1 << i;
			q.push(edges[0][i]);
		}
		while(!q.empty()) {
			int on = q.front();
			q.pop();
			for(auto to : edges[on]) {
				if(dist[to] > dist[on] + 1) {
					dist[to] = 1 + dist[on];
					q.push(to);
				}
				if(dist[to] == dist[on] + 1) {
					rep[to] |= rep[on];
				}
			}
		}
		auto inv = rep;
		for(int i = 0; i < (1 << n); i++) {
			inv[rep[i]] = i;
		}
		for(int i = 0; i < (1 << n); i++) {
			std::cout << inv[i] << (i + 1 == (1 << n) ? '\n' : ' ');
		}
		for(int i = 0; i < (1 << n); i++) {
			int kek = 0;
			for(auto j : edges[i]) {
				int val = rep[i] ^ rep[j];
				assert(val > 0 && val == (val & -val));
				kek |= val;
			}
			assert(kek == (1 << n) - 1);
		}
		if(n == (n & -n)) {
			for(int i = 0; i < (1 << n); i++) {
				int val = 0;
				for(int j = 0; j < n; j++) {
					if(rep[i] & (1 << j)) {
						val ^= j;
					}
				}
				std::cout << val << (i + 1 == (1 << n) ? '\n' : ' ');
			}
		} else {
			// guess
			std::cout << "-1\n";
		}
	}
}