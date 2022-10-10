#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		char c;
		std::cin >> c;
		if((c - '0') % 2 == 0) {
			ans += i;
		}
	}
	std::cout << ans << '\n';
}