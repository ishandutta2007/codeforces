#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long solve(long long n, long long b) {
	if(n < b) return 0;
	else return n / b + solve(n / b, b);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long n, b;
	std::cin >> n >> b;
	long long ans = 5e18;
	for(long long i = 2; i * i <= b; i++) {
		int e = 0;
		while(b % i == 0) {
			b /= i;
			e++;
		}
		if(e) {
			ans = std::min(ans, solve(n, i) / e);
		}
	}
	if(b > 1) {
		ans = std::min(ans, solve(n, b));
	}
	std::cout << ans << '\n';
}