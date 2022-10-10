#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> deg(n, 0); 
	int ans = 0;
	while(m--) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		if(u > v) std::swap(u, v);
		if(deg[u]) ans--;
		deg[u]++;
		if(deg[u]) ans++;
	}
	std::cin >> m;
	while(m--) {
		int t;
		std::cin >> t;
		if(t == 3) {
			std::cout << n - ans << '\n';
		} else {
			int u, v;
			std::cin >> u >> v;
			u--;v--;
			if(u > v) std::swap(u, v);
			if(deg[u]) ans--;
			deg[u] += t == 1 ? 1 : -1;
			if(deg[u]) ans++;
		}
	}
}