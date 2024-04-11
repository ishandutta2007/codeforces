#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 40;
const long long INF = (long long) 1e18 + 10;

long long f[ms];


void solve(long long n, long long k) {
	long long path = 3, rest = 0, bad = 1;
	if(k == 1) {
		std::cout << "YES " << n - 1 << '\n';
		return;
	}
	if(n >= ms) {
		std::cout << "YES " << n - 1 << '\n';
		return;
	}
	if(k > f[n]) {
		std::cout << "NO\n";
		return;
	}
	if(k == f[n]) {
		std::cout << "YES 0\n";
		return;
	}
	for(int i = 0; i < n; i++) {
		if(i + 1 < n)
		rest += (INF / (path-2) / f[n-i-1] == 0 ? INF : (path - 2) * f[n-i-1]);
		if(k - bad < 0) {
			std::cout << "NO\n";
			return;
		}
		if(k - bad <= rest) {
			std::cout << "YES " << n-i-1 << '\n';
			return;
		}
		bad += path;
		path = path * 2 + 1;
	}
	assert(false);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 1; i < ms; i++) {
		f[i] = 4 * f[i-1] + 1;
		f[i] = std::min(f[i], INF);
	}
	int t;
	std::cin >> t;
	while(t--) {
		long long n, k;
		std::cin >> n >> k;
		solve(n, k);
	}
}