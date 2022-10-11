#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <utility>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].first >> a[i].second;
	}
	std::sort(a.begin(), a.end());
	std::vector<int> dp(n);
	for(int i = 0; i < n; i++) {
		int idx = std::lower_bound(a.begin(), a.end(), std::pair<int, int>(a[i].first - a[i].second, -1)) - a.begin();
		idx--;
		if(idx == -1 ) {
			dp[i] = 1;
		} else {
			dp[i] = 1 + dp[idx];
		}
	}
	int ans = 0;
	for(auto v : dp) {
		ans = std::max(v, ans);
	}
	std::cout << n - ans << std::endl;
}