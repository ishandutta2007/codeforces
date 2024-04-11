#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i] += a[i - 1];
	}
	if(a[n] % k != 0) {
		std::cout << "No\n";
		return 0;
	}
	int cur = 0, f = 0;
	std::vector<int> ans;
	int want = a[n] / k;
	for(int i = 1; i <= n; i++) {
		int v = a[i] - a[i - 1];
		cur += v;
		f++;
		if(cur == want) {
			ans.push_back(f);
			cur = 0;
			f = 0;
			continue;
		}
		if(cur > want) {
			std::cout << "No\n";
			return 0;
		}
	}
	std::cout << "Yes\n";
	for(int i = 0; i < k; i++) {
		std::cout << ans[i] << (i + 1 == k ? '\n' : ' ');
	}
}