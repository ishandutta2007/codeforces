#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	int tot = 0;
	std::vector<int> sum(k, 0);
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		sum[i % k] += x;
		tot += x;
	}
	int ans = 0;
	for(int i = 0; i < k; i++) {
		ans = std::max(ans, std::max(tot-sum[i], sum[i]-tot));
	}
	std::cout << ans << '\n';
}