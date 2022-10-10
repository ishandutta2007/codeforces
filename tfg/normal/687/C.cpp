#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <bitset>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	const int ms = 505;
	int n, k;
	std::cin >> n >> k;
	std::vector<std::bitset<ms>> dp(k+1);
	dp[0][0] = true;
	while(n--) {
		int x;
		std::cin >> x;
		for(int i = k; i >= x; i--) {
			dp[i] |= dp[i-x] | (dp[i-x] << x);
		}
	}
	std::vector<int> ans;
	for(int i = 0; i <= k; i++) {
		if(dp[k][i]) {
			ans.push_back(i);
		}
	}
	std::cout << ans.size() << std::endl;
	for(int i = 0; i < (int) ans.size(); i++) {
		std::cout << ans[i] << (i+1 == (int) ans.size() ? '\n' : ' ');
	}
}