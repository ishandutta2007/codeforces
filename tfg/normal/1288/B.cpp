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
		long long a, b;
		std::cin >> a >> b;
		long long ans = 0;
		for(long long x = 10; x-1 <= b; x *= 10) {
			ans++;
		}
		ans = ans * a;
		std::cout << ans << '\n';
	}
}