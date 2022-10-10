#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	long long ans = 0;
	for(int l = 2, r; l <= n; l = r + 1) {
		r = n / (n / l);
		// n / i has the same value for l <= i <= r
		long long cnt = n / l;
		ans += (cnt * (cnt + 1) / 2 - 1) * (r - l + 1);
	}
	ans *= 4;
	std::cout << ans << '\n';
}