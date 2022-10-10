#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <map>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n, m;
		std::cin >> n >> m;
		std::map<int, std::pair<int, int>> f;
		while(n--) {
			int x;
			std::cin >> x;
			x %= m;
			if(x < m - x) {
				f[x].first++;
			} else {
				f[m-x].second++;
			}
		}
		int ans = 0;
		for(auto it : f) {
			//std::cout << it.first << ", (" << it.second.first << ", " << it.second.second << ")\n";
			if(it.first == (m - it.first) % m) {
				ans++;
			} else {
				int a[2] = {it.second.first, it.second.second};
				std::sort(a, a + 2);
				ans += std::max(a[1] - a[0], 1);
			}
		}
		std::cout << ans << '\n';
	}
}