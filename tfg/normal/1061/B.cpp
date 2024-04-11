#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	long long sum = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		sum += a[i];
	}
	std::sort(a.begin(), a.end());
	int cur = 0;
	for(auto v : a) {
		if(v <= cur) continue;
		else if(cur < m) cur++;
	}
	sum -= a.back();
	sum -= n - cur;
	std::cout << sum << '\n';
}