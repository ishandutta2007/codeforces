#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 101;
const long double INF = 1e18;

// dp[how many I got][cur sum] = minimum time to get this
long double dp[ms][10 * ms], mult[ms];
std::pair<long double, int> a[ms];

void solve() {
	int n;
	std::cin >> n;
	long double c, t;
	std::cin >> c >> t;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].first >> a[i].second;
	}
	for(int i = 0; i < ms; i++) {
		for(int j = 0; j < 10 * ms; j++) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	mult[0] = 1;
	for(int i = 1; i <= n; i++) {
		mult[i] = mult[i-1] / 0.9;
	}
	std::sort(a, a + n, std::greater<std::pair<long long, int>>());
	int sum = 0;
	for(int i = 0; i < n; i++) {
		int co = a[i].second;
		//std::cout << "solving for (" << (double) a[i].first << ", " << a[i].second << ")" << std::endl;
		for(int j = i; j >= 0; j--) {
			for(int k = sum; k >= 0; k--) {
				dp[j+1][k+co] = std::min(dp[j+1][k+co], dp[j][k] + a[i].first * mult[j+1]);
			}
		}
		sum += co;
	}
	//std::cout << "GOT HERE!" << std::endl;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= sum; j++) {
			long double x = dp[i][j], y = 10 * i;
			if(x + y - t <= 1e-9) {
				ans = std::max(ans, j);
				continue;
			}
			// cost(time of training)
			// cost(T) = (1 / (1 + T * C)) * x + y + T
			// cost(T) = x / (1 + T * C) + y + T
			// cost'(T) = -xC / (1 + T * C)^2 + 1
			// xC / (1 + T * C)^2 == 1
			// x == (1 + T * C)^2 / C
			// (1 + 2TC + T^2C^2) / C - x == 0
			// T^2C + 2T + (1 / C - x) == 0
			long double c2 = c, c1 = 2, c0 = 1 / c - x;
			// 4 * c * (1 / c - x) == 4 * (1 - x)
			long double perfect = (-c1 + sqrtl(std::max(c1 * c1 - 4 * c0 * c2, (long double) 0))) / (2 * c2);
			perfect = std::max(perfect, (long double) 0.0);
			if(x / (1 + perfect * c) + y + perfect - t <= 1e-9) {
				ans = std::max(ans, j);
			}
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