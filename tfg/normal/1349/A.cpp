#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	long long g = 0;
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		ans = gcd(ans, lcm(a[i], g));
		g = gcd(g, a[i]);
	}
	std::cout << ans << '\n';
}