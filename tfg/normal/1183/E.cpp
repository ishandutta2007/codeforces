#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int dp[101][101];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::string str;
	std::cin >> str;
	for(int i = n-1; i >= 0; i--) {
		for(int j = i, mask = 0; j < n; j++) {
			if(mask & (1 << (str[j] - 'a'))) continue;
			mask |= 1 << (str[j] - 'a');
			dp[i][1]++;
			for(int x = 0; x < n; x++) {
				dp[i][x+1] = std::min(dp[i][x+1] + dp[j+1][x], k);
			}
		}
	}
	long long ans = 0;
	dp[0][0]++;
	for(int i = n; i >= 0; i--) {
		while(k > 0 && dp[0][i] > 0) {
			ans += n - i;
			k--;
			dp[0][i]--;
		}
	}
	if(k > 0) {
		ans = -1;
	}
	std::cout << ans << '\n';
}