#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> a;
	std::vector<int> p(n);
	for(int i = 0; i < n; i++) {
		std::vector<int> b(n);
		p[i] = i;
		for(int j = 0; j < n; j++) {
			std::cin >> b[j];
		}
		std::sort(b.rbegin(), b.rend());
		a.push_back(b);
	}
	std::sort(p.begin(), p.end(), [&](int v1, int v2) { return a[v1] < a[v2]; });
	std::vector<int> ans(n);
	for(int i = 0; i < n; i++) {
		ans[p[i]] = i + 1;
	}
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] << (i+1==n?'\n':' ');
	}
}