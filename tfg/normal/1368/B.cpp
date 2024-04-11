#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long k;
	std::cin >> k;
	std::string want = "codeforces";
	int n = (int) want.size();
	std::vector<int> a(n, 1);
	auto f = [&]() {
		long long ans = k-1;
		for(auto x : a) ans /= x;
		return ans;
	};
	int i = 0;
	while(f() > 0) {
		a[i]++;
		i = (i + 1) % n;
	}
	for(i = 0; i < n; i++) {
		while(a[i]--) {
			std::cout << want[i];
		}
	}
	std::cout << '\n';
}