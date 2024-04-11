#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n, a, b;
		std::string str;
		std::cin >> n >> a >> b >> str;
		const long long INF = 1e18;
		long long dp[2] = {b, INF};
		for(auto c : str) {
			
			if(c == '1') {
				dp[0] = INF;
			}
			long long nxt[2];
			nxt[0] = std::min(dp[0], dp[1] + a) + b + a;
			nxt[1] = std::min(dp[1], dp[0] + a) + 2 * b + a;
			std::swap(nxt[0], dp[0]);
			std::swap(nxt[1], dp[1]);
			if(c == '1') {
				dp[0] = INF;
			}
		}
		std::cout << dp[0] << std::endl;
	}
}