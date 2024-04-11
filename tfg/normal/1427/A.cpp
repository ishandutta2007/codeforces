#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n;
	std::cin >> n;
	int sum = 0;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		sum += a[i];
	}
	if(sum == 0) {
		std::cout << "NO\n";
		return;
	}
	std::sort(a.begin(), a.end());
	bool good = true;
	sum = 0;
	for(auto x : a) {
		sum += x;
		if(sum == 0) good = false;
	}
	if(!good) {
		std::reverse(a.begin(), a.end());
	}
	std::cout << "YES\n";
	for(int i = 0; i < n; i++) {
		std::cout << a[i] << (i + 1 == n ? '\n' : ' ');
	}
}
int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}