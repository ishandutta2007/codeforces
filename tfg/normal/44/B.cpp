#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, a, b, c;
	std::cin >> n >> a >> b >> c;
	int ans = 0;
	for(int i = 0; i <= a; i += 2) {
		for(int j = 0; j <= c && 2 * j + i / 2 <= n; j++) {
			int rest = n - 2 * j - i / 2;
			if(rest <= b) ans++;
		}
	}
	std::cout << ans << '\n';
}