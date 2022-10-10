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
	std::vector<int> a[2];
	int x = 0;
	a[0].push_back(x);
	for(int i = 1; i <= n; i++) {
		int v;
		std::cin >> v;
		x ^= v;
		a[i % 2].push_back(x);
	}
	long long ans = 0;
	for(int i = 0; i < 2; i++) {
		std::sort(a[i].begin(), a[i].end());
		for(int l = 0, r = 0; l < (int) a[i].size(); l = r) {
			while(r < (int) a[i].size() && a[i][r] == a[i][l]) {
				r++;
			}
			long long size = r - l;
			ans += size * (size - 1) / 2;
		}
	}
	std::cout << ans << '\n';
}