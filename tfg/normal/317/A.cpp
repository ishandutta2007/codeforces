#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long x, y, m;
	std::cin >> x >> y >> m;
	if(y < x) std::swap(x, y);
	if(y >= m) {
		std::cout << "0\n";
		return 0;
	}
	long long ans = 0;
	if(y <= 0) {
		std::cout << "-1\n";
		return 0;
	}
	int rep = 0;
	while(y < m) {
		assert(rep++ <= 200 && y >= x);
		long long use = (y - x) / y + 1;
		x += use * y;
		ans += use;
		std::swap(x, y);
	}
	std::cout << ans << '\n';
}