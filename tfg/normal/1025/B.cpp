#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].first >> a[i].second;
	}
	std::vector<int> divs;
	for(int i = 2, x = a[0].first; x != 1; i++) {
		if(i * i > x) i = x;
		if(x % i == 0) {
			divs.push_back(i);
			while(x % i == 0) x /= i;
		}
	}
	for(int i = 2, x = a[0].second; x != 1; i++) {
		if(i * i > x) i = x;
		if(x % i == 0) {
			divs.push_back(i);
			while(x % i == 0) x /= i;
		}
	}
	std::sort(divs.begin(), divs.end());
	divs.resize(std::unique(divs.begin(), divs.end()) - divs.begin());
	int ans = -1;
	for(auto x : divs) {
		bool valid = true;
		for(auto p : a) {
			valid = valid && (p.first % x == 0 || p.second % x == 0);
		}
		if(valid) ans = x;
	}
	std::cout << ans << '\n';
}