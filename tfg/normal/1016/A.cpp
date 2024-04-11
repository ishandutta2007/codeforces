#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	int cur = 0;
	while(n--) {
		int a;
		std::cin >> a;
		int ans = a / m;
		cur += a % m;
		ans += cur / m;
		cur %= m;
		std::cout << ans << '\n';
	}
}