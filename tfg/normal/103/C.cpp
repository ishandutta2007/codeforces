#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long n, k, p;
	std::cin >> n >> k >> p;
	while(p--) {
		long long x = 0;
		std::cin >> x;
		if(k == 0) {
			std::cout << '.';
			continue;
		}
		x--;
		if(k == 1) {
			std::cout << (x + 1 == n ? 'X' : '.');
		} else if(k * 2 <= n+1) {
			// can have K spots
			if(n % 2 == 0) {
				// can have every single one odd
				// .......X.X.X.X
				if(x % 2 == (n-1) % 2 && (n-1-x)/2 < k) {
					std::cout << 'X';
				} else {
					std::cout << '.';
				}
			} else {
				// almost the same but doubled in the end
				// ....X.X.X.XX
				// X.X.X.XX
				if(x == (n-1) || (x % 2 == (n-2) % 2 && (n-2-x)/2 < k-1)) {
					std::cout << 'X';
				} else {
					std::cout << '.';
				}
			}
		} else {
			// X.X.X.X.XXX
			if(x%2 == (n-1-n%2) % 2 || (n+1)/2 + (n-2-n%2-x)/2 < k) {
				std::cout << 'X';
			} else {
				std::cout << '.';
			}
		}
	}
}