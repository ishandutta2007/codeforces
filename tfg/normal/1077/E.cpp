#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	std::vector<int> f;
	for(int l = 0, r = 0; l < n; l = r) {
		while(r < n && a[l] == a[r]) r++;
		f.push_back(r - l);
	}
	std::sort(f.begin(), f.end());
	n = (int) f.size();
	int ans = 0;
	const int MAGIC = 23;
	std::vector<int> dp(MAGIC, -1);
	dp[0] = (int) 1e9;
	for(int i = n-1; i >= 0; i--) {
		//std::cout << "on " << i << ", " << f[i] << "\n";
		for(int j = MAGIC - 2; j >= 0; j--) {
			// from j create j + 1
			if(f[i] + f[i] <= dp[j]) {
				//std::cout << "creating " << f[i] << " on " << j << "\n";
				dp[j+1] = std::max(dp[j+1], f[i]);
			} else if(dp[j] / 2 > 0) {
				dp[j+1] = std::max(dp[j+1], std::min(f[i], dp[j] / 2));
			}
		}
	}
	for(int i = 1; i < MAGIC; i++) {
		ans = std::max(ans, ((1 << i) - 1) * dp[i]);
	}
	std::cout << ans << '\n';
}