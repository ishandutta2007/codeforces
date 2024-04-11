#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	const int ms = 1001000;
	int n;
	std::cin >> n;
	std::vector<long long> a(ms, 0);
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		a[x - i + n] += x;
	}
	long long ans = 0;
	for(auto x : a) {
		ans = std::max(ans, x);
	}
	std::cout << ans << '\n';
}