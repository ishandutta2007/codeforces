#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n, p, k;
	std::cin >> n >> p >> k;
	std::string str;
	std::cin >> str;
	std::vector<int> dp(n, 0);
	int x, y;
	std::cin >> x >> y;
	int ans = 1e9;
	for(int i = n-1; i >= 0; i--) {
		dp[i] = str[i] == '1' ? 0 : x;
		if(i+k < n) {
			dp[i] += dp[i+k];
		}
		int st = i - p + 1;
		if(st >= 0) {
			ans = std::min(ans, st * y + dp[i]);
		}
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}