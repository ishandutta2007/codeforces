#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const long long MAGIC = 1e12;
const int ms = 1001000;

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) {
	if(MAGIC / (a / gcd(a, b)) / b == 0) return MAGIC;
	return a / gcd(a, b) * b;
}

std::vector<long long> divs(long long n) {
	std::vector<long long> wtf;
	if(n >= MAGIC) {
		return wtf;
	}
	for(long long i = 1; i * i <= n; i++) {
		if(n % i == 0) {
			wtf.push_back(i);
			if(n / i != i) {
				wtf.push_back(n / i);
			}
		}
	}
	std::sort(wtf.begin(), wtf.end());
	return wtf;
}


void solve() {
	long long ans = 1;
	int n;
	std::cin >> n;
	std::vector<long long> wtf(n);
	for(int i = 0; i < n; i++) {
		std::cin >> wtf[i];
		ans = lcm(ans, wtf[i]);
	}
	std::sort(wtf.begin(), wtf.end());
	if(ans == wtf.back()) {
		ans *= wtf[0];
	}
	if(ans >= MAGIC) {
		std::cout << "-1\n";
		return;
	}
	wtf.push_back(1);
	wtf.push_back(ans);
	std::sort(wtf.begin(), wtf.end());
	wtf.erase(std::unique(wtf.begin(), wtf.end()), wtf.end());
	std::cout << (wtf == divs(ans) ? ans : -1LL) << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}