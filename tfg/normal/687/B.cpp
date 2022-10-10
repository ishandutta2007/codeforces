#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	int ans = 1;
	while(n--) {
		int x;
		std::cin >> x;
		ans = lcm(ans, gcd(x, k));
	}
	std::cout << (ans == k ? "Yes" : "No") << '\n';
}