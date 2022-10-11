#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long n, m;
	int q;
	std::cin >> n >> m >> q;
	long long g = gcd(n, m);
	auto group = [&](long long s, int e) {
		s--;
		return s / (e==1?n/g:m/g);
	};
	while(q--) {
		long long s[2];
		int e[2];
		std::cin >> e[0] >> s[0] >> e[1] >> s[1];
		std::cout << (group(s[0], e[0]) == group(s[1], e[1]) ? "YES\n" : "NO\n");
	}
}