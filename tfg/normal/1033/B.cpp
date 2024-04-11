#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

bool prime(long long x) {
	for(long long i = 2; i * i <= x; i++) {
		if(x % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		long long a, b;
		std::cin >> a >> b;
		std::cout << (a - b == 1 && prime(a + b) ? "YES\n" : "NO\n");
	}
}