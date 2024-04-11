#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, a, b;
	std::cin >> n >> a >> b;
	a *= 1;
	b *= 5;
	int ans = n;
	for(int i = 0; i * a <= n && i <= 50000; i++) {
		int cur = n - ((n / a) - i) * a;
		cur %= b;
		ans = std::min(ans, cur);
	}
	std::cout << ans << '\n';
}