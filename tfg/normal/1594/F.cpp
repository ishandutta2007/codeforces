#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		long long s, n, k;
		std::cin >> s >> n >> k;
		long long mn = n + (n / k) * k;
		if(s < k) std::cout << "NO\n";
		else if(n >= k) std::cout << (s < mn ? "YES\n" : "NO\n");
		else std::cout << (s == k ? "YES\n" : "NO\n");
	}
}