#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const long long INF = (long long) 1e18;
const int ms = 300100;

long long a[2][ms], n;
long long sum[2][ms];

long long strat[2][ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[0][i];
		sum[0][i] = a[0][i] + sum[0][i-1];
	}
	for(int i = 1; i <= n; i++) {
		std::cin >> a[1][i];
		sum[1][i] = a[1][i] + sum[1][i-1];
	}
	for(int i = n; i > 0; i--) {
		strat[1][i] = strat[1][i + 1];
		long long bef = 2 * (i - 1);
		// upper part will have bef and lower part will subtract the suffix sum and have 2 * n * ..
		strat[1][i] -= sum[1][n] - sum[1][i] + sum[0][n] - sum[0][i];
		strat[1][i] += bef * a[0][i] + (2LL * n - 1) * a[1][i];
		strat[0][i] = strat[0][i + 1];
		strat[0][i] -= sum[1][n] - sum[1][i] + sum[0][n] - sum[0][i];
		strat[0][i] += bef * a[1][i] + (2LL * n - 1) * a[0][i];
	}
	long long ans = -INF;
	long long cur = 0;
	int t = 0;
	for(int i = 1; i <= n; i++) {
		if(i % 2 == 1) {
			// is in upper part
			// uses strat 1
			ans = std::max(ans, strat[1][i] + cur);
			cur += (t++) * a[0][i];
			cur += (t++) * a[1][i];
		} else {
			ans = std::max(ans, strat[0][i] + cur);
			cur += (t++) * a[1][i];
			cur += (t++) * a[0][i];
		}
	}
	ans = std::max(ans, cur);
	std::cout << ans << std::endl;
}