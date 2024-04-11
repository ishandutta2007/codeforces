#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;
const long long INF = (long long) 1e13;

std::vector<long long> can[ms];

long long s(long long x) {
	if(x <= 0) {
		return -1;
	}
	long long ans = (long long)(sqrtl(x) + 2);
	while(ans * ans > x) ans--;
	if(ans * ans != x) ans = -1;
	return ans;
}

long long dp[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		if(i & 1) {
			// lazy step
			dp[i] = dp[i - 1] + 1;
		} else {
			// weird step
			dp[i] = dp[i - 1] + 1;
			long long v;
			std::cin >> v;
			while(dp[i] * dp[i] <= INF && s(dp[i] * dp[i] - v) < dp[i - 1]) {
				dp[i]++;
			}
			if(dp[i] * dp[i] > INF) {
				std::cout << "No\n";
				return 0;
			}
			dp[i - 1] = s(dp[i] * dp[i] - v);
		}
	}
	std::cout << "Yes\n";
	for(int i = 1; i <= n; i++) {
		std::cout << (dp[i] * dp[i] - dp[i - 1] * dp[i - 1]) << (i == n ? '\n' : ' ');
	}
}