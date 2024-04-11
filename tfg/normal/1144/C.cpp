#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::vector<int> ans[2];
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	auto can = [](std::vector<int> &v, int x) {
		return v.empty() || x > v.back();
	};
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	for(auto x : a) {
		if(can(ans[0], x)) {
			ans[0].push_back(x);
		} else if(can(ans[1], x)) {
			ans[1].push_back(x);
		} else {
			std::cout << "NO\n";
			return 0;
		}
	}
	std::reverse(ans[1].begin(), ans[1].end());
	std::cout << "YES\n";
	for(int i = 0; i < 2; i++) {
		std::cout << ans[i].size() << '\n';
		for(int j = 0; j < (int) ans[i].size(); j++) {
			std::cout << ans[i][j] << (j + 1 == (int) ans[i].size() ? '\n' : ' ');
		}
	}
}