#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) std::cin >> a[i];
	for(int i = 0; i < n; i++) std::cin >> b[i];
	const long long INF = 1e18;
	long long ans = INF;
	for(int rep = 0; rep < 2; rep++) {
		long long dp[2] = {INF, INF};
		dp[rep] = 0;
		for(int i = 0; i < n; i++) {
			//std::cout << "at " << i << " got (" << dp[0] << ", " << dp[1] << ")\n";
			long long nxt[2];
			long long cur[2] = {a[i], a[(i+1)%n]};
			long long val = b[i];
			// not choosing, choosing
			nxt[0] = val + std::min(dp[0], dp[1]);
			nxt[1] = std::min(val + std::min(dp[0], dp[1]), dp[1]) + cur[1];
			dp[0] = nxt[0], dp[1] = nxt[1];
		}
		//std::cout << "at " << n << " got (" << dp[0] << ", " << dp[1] << ")\n";
		ans = std::min(ans, dp[rep]);
	}
	long long sum = 0;
	for(int i = 0; i < n; i++) sum += a[i];
	std::cout << (sum == ans ? "YES\n" : "NO\n");
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}