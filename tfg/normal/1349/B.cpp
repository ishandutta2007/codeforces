#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

bool solve(const std::vector<int> &a) {
	int n = (int) a.size();
	bool good = false;
	for(auto x : a) good = good || x == 0;
	if(!good) return false;
	for(int i = 0; i + 1 < n; i++) {
		if(a[i] >= 0 && a[i+1] >= 0) return true;
	}
	for(int i = 0; i + 2 < n; i++) {
		if(a[i] >= 0 && a[i+2] >= 0) return true;
	}
	return n == 1;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n, k;
		std::cin >> n >> k;
		std::vector<int> a(n);
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
			if(a[i] > k) a[i] = 1;
			else if(a[i] == k) a[i] = 0;
			else a[i] = -1;
		}
		std::cout << (solve(a) ? "yes\n" : "no\n");
	}
}