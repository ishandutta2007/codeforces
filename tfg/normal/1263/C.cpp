#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::vector<int> ans;
		for(int i = 1; i <= n; i = n / (n / i) + 1) {
			ans.push_back(n / i);
		}
		ans.push_back(0);
		std::reverse(ans.begin(), ans.end());
		std::cout << ans.size() << '\n';
		for(int i = 0; i < (int) ans.size(); i++) {
			std::cout << ans[i] << (i + 1 == (int) ans.size() ? '\n' : ' ');
		}
	}
}