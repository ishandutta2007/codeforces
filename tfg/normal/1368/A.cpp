#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		long long a, b, n;
		int ans = 0;
		std::cin >> a >> b >> n;
		while(std::max(a, b) <= n) {
			if(a < b) a += b;
			else b += a;
			ans++;
		}
		std::cout << ans << '\n';
	}
}