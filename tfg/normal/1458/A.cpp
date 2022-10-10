#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<long long> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	long long hmm = 0;
	for(int i = 1; i < n; i++) {
		hmm = gcd(a[i] - a[i-1], hmm);
	}
	while(m--) {
		long long x;
		std::cin >> x;
		std::cout << gcd(x + a[0], hmm) << ' ';
	}
	std::cout << '\n';
}