#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> ans;
	for(int i = 1; i <= n; i++) {
		ans.emplace_back(i, i);
		ans.emplace_back(i+1, i);
		ans.emplace_back(i-1, i);
		ans.emplace_back(i, i+1);
		ans.emplace_back(i, i-1);
	}
	for(int i = n; i >= 0; i--) {
		ans.emplace_back(i, n+2);
		ans.emplace_back(n+2, i);
	}
	for(int i = 1; i <= n+2; i++) {
		ans.emplace_back(i, -1);
		ans.emplace_back(-1, i);
	}
	std::sort(ans.begin(), ans.end());
	ans.resize(std::unique(ans.begin(), ans.end()) - ans.begin());
	std::cout << ans.size() << '\n';
	for(auto p : ans) {
		std::cout << p.first + 1 << ' ' << p.second + 1 << '\n';
	}
}