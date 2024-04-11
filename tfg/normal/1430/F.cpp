#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> l(n), r(n), a(n);
	std::vector<long long> dp(n+1, 2e18);
	dp[0] = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> l[i] >> r[i] >> a[i];
	}
	for(int i = 0; i < n; i++) {
		int current = k;
		long long waste = 0;
		for(int j = i; j < n; j++) {
			int mon = a[j];
			if(((long long) r[j] - l[j]) * k < mon - current) break;
			waste += mon;
			{
				int use = std::min(mon, current);
				mon -= use;
				current -= use;
			}
			int daysUsed = (mon + k - 1) / k;
			if(current == 0) {
				current = (k - mon % k) % k;
			}
			//std::cout << "current is " << current << ", from " << i << " to " << j+1 << " with " << dp[i] + waste + (j+1 == n ? 0 : current) << '\n';
			if(j+1 == n || (j+1 < n && daysUsed+1 <= l[j+1] - l[j])) dp[j+1] = std::min(dp[j+1], dp[i] + waste + (j+1 == n ? 0 : current));
		}
	}
	std::cout << (dp.back() < (long long) 2e18 ? dp.back() : -1LL) << '\n';
}