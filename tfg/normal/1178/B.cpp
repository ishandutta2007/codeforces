#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	std::cin >> str;
	long long dp[4] = {1, 0, 0, 0};
	for(int i = 0; i < (int) str.size(); i++) {
		if(i + 1 < (int) str.size() && str[i] == str[i+1] && str[i] == 'v') {
			dp[1] += dp[0];
			dp[3] += dp[2];
		} else if(str[i] == 'o') {
			dp[2] += dp[1];
		}
	}
	std::cout << dp[3] << '\n';
}