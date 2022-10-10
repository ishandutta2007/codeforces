#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::string str;
	std::cin >> n >> str;
	const long long INF = 1e18;
	long long dp[4] = {0, INF, INF, INF};
	for(int i = 0; i < n; i++) {
		int a;
		std::cin >> a;
		if(str[i] == 'h') {
			int j = 0;
			dp[j+1] = std::min(dp[j+1], dp[j]);
			dp[j] += a;
		} else if(str[i] == 'a') {
			int j = 1;
			dp[j+1] = std::min(dp[j+1], dp[j]);
			dp[j] += a;
		} else if(str[i] == 'r') {
			int j = 2;
			dp[j+1] = std::min(dp[j+1], dp[j]);
			dp[j] += a;
		} else if(str[i] == 'd') {
			dp[3] += a;
		}
	}
	for(int i = 1; i < 4; i++) {
		dp[0] = std::min(dp[0], dp[i]);
	}
	std::cout << dp[0] << '\n';
}