#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 5050;

int dp[ms][ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	for(int l = 0, r = 0; l < n; l++) {
		while(r < n && a[r] - a[l] <= 5) {
			r++;
		}
		for(int i = 0; i <= k; i++) {
			dp[l+1][i] = std::max(dp[l][i], dp[l+1][i]);
			if(i) dp[r][i] = std::max(dp[r][i], dp[l][i-1] + r - l);
		}
	}
	std::cout << dp[n][k] << '\n';
}