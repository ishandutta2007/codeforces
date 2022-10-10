#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long n, m, k;
	std::cin >> n >> m >> k;
	long long ans = -1;
	for(long long l = 1, r; l <= n; l = r + 1) {
		r = n / (n / l);
		// making r-1 cuts
		// we can get side size n / r
		long long side = n / r;
		long long need = std::max(0LL, k - (r - 1));
		if(need > m - 1) continue;
		ans = std::max(ans, side * (m / (need + 1)));
	}
	std::cout << ans << '\n';
}