#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int mn = 0, mx = 0;
	while(n--) {
		char c;
		int x, y;
		std::cin >> c >> x >> y;
		if(x > y) std::swap(x, y);
		if(c == '+') {
			mn = std::max(mn, x);
			mx = std::max(mx, y);
		} else {
			std::cout << (mn <= x && mx <= y ? "YES\n" : "NO\n");
		}
	}
}