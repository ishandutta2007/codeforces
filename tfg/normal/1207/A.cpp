#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int b, p, f;
		std::cin >> b >> p >> f;
		int h, c;
		std::cin >> h >> c;
		b /= 2;
		if(h < c) {
			std::swap(p, f);
			std::swap(h, c);
		}
		int ans = 0;
		int use;
		use = std::min(b, p);
		ans += use * h;
		b -= use;
		use = std::min(b, f);
		ans += use * c;
		std::cout << ans << '\n';
	}
}