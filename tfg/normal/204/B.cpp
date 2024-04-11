#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::map<int, std::pair<int, int>> f;
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		int x, y;
		std::cin >> x >> y;
		f[x].first++;
		if(x != y) {
			f[y].second++;
		}
	}
	int ans = n + 1;
	for(auto it : f) {
		if(it.second.first + it.second.second >= (n + 1) / 2) {
			if(it.second.first >= (n + 1) / 2) {
				ans = std::min(ans, 0);
				//std::cout << "at " << it.first << " got cost " << 0 << '\n';
			} else {
				ans = std::min(ans, (n + 1) / 2 - it.second.first);
				//std::cout << "at " << it.first << " got cost " << (n+1)/2 - it.second.first << '\n';
			}
		}
	}
	if(ans > n) {
		ans = -1;
	}
	std::cout << ans << '\n';
}