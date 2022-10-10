#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int q;
	std::cin >> q;
	while(q--) {
		int n;
		std::cin >> n;
		std::vector<int> l(n, n + 1), r(n, -1);
		for(int i = 0; i < n; i++) {
			int x;
			std::cin >> x;
			x--;
			l[x] = std::min(l[x], i);
			r[x] = i;
		}
		std::vector<std::pair<int, int>> a;
		for(int i = 0; i < n; i++) {
			if(l[i] == n + 1) continue;
			a.emplace_back(l[i], r[i]);
		}
		std::vector<int> dp(a.size(), 1);
		int ans = (int) dp.size() - 1;
		for(int i = (int) dp.size() - 2; i >= 0; i--) {
			if(a[i].second < a[i+1].first) {
				dp[i] += dp[i+1];
			}
			ans = std::min(ans, (int) dp.size() - dp[i]);
		}
		std::cout << ans << '\n';
	}
}