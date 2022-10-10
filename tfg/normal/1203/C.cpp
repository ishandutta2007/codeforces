#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	long long g = 0;
	while(n--) {
		long long x;
		std::cin >> x;
		g = gcd(g, x);
	}
	int ans = 0;
	for(long long i = 1; i * i <= g; i++) {
		if(g % i == 0) {
			ans++;
			if(i * i != g) {
				ans++;
			}
		}
	}
	std::cout << ans << '\n';
}