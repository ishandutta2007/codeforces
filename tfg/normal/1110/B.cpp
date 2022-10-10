#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<int> a(n);
	std::vector<int> b;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(i) {
			b.push_back(a[i] - a[i-1]);
		}
	}
	long long ans = 1;
	std::sort(b.begin(), b.end());
	while(k > 1) {
		b.pop_back();
		k--;
		ans++;
	}
	for(auto v : b) {
		ans += v;
	}
	std::cout << ans << '\n';
}