#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

std::pair<long long, long long> solve(long long n) {
	long long ans = 1;
	for(int i = 1; i < n; i++) {
		if(lcm(i, n-i) < lcm(ans, n-ans)) {
			ans = i;
		}
	}
	return std::pair<long long, long long>(ans, n-ans);
}

std::pair<long long, long long> mySolve(int n) {
	std::set<int> divs;
	for(int i = 1; i*i <= n; i++) {
		if(n % i == 0) {
			divs.insert(i);
			divs.insert(n/i);
		}
	}
	long long ans[2] = {1, n-1};
	auto consider = [&](long long a, long long b) {
		assert(a + b == n && std::min(a, b) > 0);
		if(lcm(a, b) < lcm(ans[0], ans[1])) {
			ans[0] = a, ans[1] = b;
		}
	};
	divs.erase(n);
	for(auto d : divs) {
		// try both being multiple of d
		// d * (i + j) == n
		// (i + j) == n / d
		// minimizing i*j
		consider(d, n - d);
	}
	return std::pair<long long, long long>(ans[0], ans[1]);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		long long ans[2];
		auto got = mySolve(n);
		ans[0] = got.first, ans[1] = got.second;
		std::cout << ans[0] << ' ' << ans[1] << '\n';
		//std::cout << "should be " << solve(n) << ", answer is " << lcm(ans[0], ans[1]) << '\n';
	}
}