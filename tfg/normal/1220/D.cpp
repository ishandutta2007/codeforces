#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	//01010101
	//00110011
	int n;
	std::cin >> n;
	const int me = 65;
	std::vector<long long> a[me];
	for(int i = 0; i < n; i++) {
		long long x;
		std::cin >> x;
		int l = 0;
		while(x % 2 == 0) {
			x /= 2;
			l++;
		}
		a[l].push_back(x * (1LL << l));
	}
	int mx = 0;
	for(int i = 0; i < me; i++) {
		if(a[i].size() > a[mx].size()) {
			mx = i;
		}
	}
	std::cout << n - a[mx].size() << '\n';
	for(int j = 0; j < me; j++) {
		if(j == mx) continue;
		for(auto i : a[j]) {
			std::cout << i << '\n';
		}
	}
}