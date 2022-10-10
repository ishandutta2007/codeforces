#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int getMax(long long x) { return x == 0 ? 0 : std::max((int) (x % 10), getMax(x / 10)); }
int getMin(long long x) { return x == 0 ? 10 : std::min((int) (x % 10), getMin(x / 10)); }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		long long x, k;
		std::cin >> x >> k;
		while(k > 1 && getMin(x) > 0) {
			x += getMin(x) * getMax(x);
			k--;
		}
		std::cout << x << '\n';
	}
}