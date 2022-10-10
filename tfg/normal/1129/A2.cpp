#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> a(n);
	for(int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		a[u].push_back(v);
	}
	std::vector<int> b(n, n);
	for(int i = 0; i < n; i++) {
		std::sort(a[i].begin(), a[i].end());
		for(auto j : a[i]) {
			b[i] = std::min(b[i], (j-i+n)%n);
		}
		//std::cout << "b[" << i << "] = " << b[i] << '\n';
	}
	for(int s = 0; s < n; s++) {
		int ans = 0;
		for(int i = 0; i < n; i++) {
			int on = (s+i);
			if(on >= n) {
				on -= n;
			}
			if(a[on].empty()) {
				continue;
			}
			int base = n * ((int) a[on].size() - 1) + i;
			ans = std::max(ans, base + b[on]);
		}
		std::cout << ans << (s + 1 == n ? '\n' : ' ');
	}
}