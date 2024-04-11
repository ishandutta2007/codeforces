#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long n, m;
	std::cin >> n >> m;
	long long ans = 0;
	while((ans - 1) * ans / 2 < m) {
		ans++;
	}
	std::cout << std::max(n - 2 * m, 0LL) << ' ' << n - ans << std::endl;
}