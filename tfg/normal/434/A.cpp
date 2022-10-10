#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

std::vector<int> a[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> m >> n;
	std::vector<int> b(n);
	for(int i = 0; i < n; i++) {
		std::cin >> b[i];
	}
	for(int i = 0; i+1 < n; i++) {
		if(b[i] != b[i+1]) {
			//std::cout << "pushing " << b[i] << ", " << b[i+1] << std::endl;
			a[b[i]].push_back(b[i+1]);
			a[b[i+1]].push_back(b[i]);
		}
	}
	long long base = 0;
	for(int i = 0; i+1 < n; i++) {
		base += abs(b[i] - b[i+1]);
	}
	long long ans = base;
	for(int i = 1; i <= m; i++) {
		if(a[i].empty()) continue;
		std::sort(a[i].begin(), a[i].end());
		long long dif = 0;
		for(auto v : a[i]) {
			dif += abs(v - a[i][a[i].size()/2]) - abs(i - v);
		}
		//std::cout << "diff for " << i << " is " << dif << std::endl;
		ans = std::min(ans, base + dif);
	}
	std::cout << ans << std::endl;
}