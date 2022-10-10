#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <bitset>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 101 * 101 * 10 * 2;

int dp[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	for(int i = 0; i < ms; i++) {
		dp[i] = -(int) 1e9;
	}
	std::vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		std::cin >> b[i];
	}
	dp[ms / 2] = 0;
	for(int j = 0; j < n; j++) {
		int v = a[j] - k * b[j];
		//std::cout << "got " << a[j] << " - " << k << " * " << b[j] << std::endl;
		if(v < 0) {
			for(int i = 0; i - v < ms; i++) {
				dp[i] = std::max(dp[i], dp[i-v] + a[j]);
			}
		} else {
			for(int i = ms-1; i - v >= 0; i--) {
				dp[i] = std::max(dp[i], dp[i-v] + a[j]);
			}
		}
	}
	int ans = dp[ms/2];
	if(ans == 0) ans = -1;
	std::cout << ans << '\n';
}