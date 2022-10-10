#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1001000;
const int MOD = 1e9 + 7;

std::vector<int> divs[ms];
int dp[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 1; i < ms; i++) {
		for(int j = i; j < ms; j += i) {
			divs[j].push_back(j / i);
		}
	}
	dp[0] = 1;
	int n;
	std::cin >> n;
	while(n--) {
		int v;
		std::cin >> v;
		for(auto d : divs[v]) {
			dp[d] = (dp[d] + dp[d-1] < MOD ? dp[d] + dp[d-1] : dp[d] + dp[d-1] - MOD);
		}
	}
	int ans = 0;
	for(int i = 1; i < ms; i++) {
		ans = (ans + dp[i]) % MOD;
	}
	std::cout << ans << '\n';
}