#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long a, b, x, y;
	std::cin >> a >> b >> x >> y;
	long long g = gcd(x, y);
	x /= g;
	y /= g;
	std::cout << std::min(a / x, b / y) << std::endl;
}