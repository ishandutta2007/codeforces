#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		long long p, q, b;
		std::cin >> p >> q >> b;
		while((b = gcd(q, b)) > 1) {
			q /= b;
		}
		q /= gcd(q, p);
		std::cout << (q == 1 ? "Finite\n" : "Infinite\n");
	}
}