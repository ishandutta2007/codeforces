#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::vector<int> a(2*n);
		for(int i = 0; i < 2*n; i++) {
			std::cin >> a[i];
		}
		std::vector<std::pair<int, int>> ans;
		for(int i = 0; i < 2*n; i++) {
			for(int j = i+1; j < 2*n; j++) {
				if(a[i] != -1 && a[j] != -1 && (a[i] + a[j]) % 2 == 0) {
					ans.emplace_back(i, j);
					a[i] = a[j] = -1;
				}
			}
		}
		while((int) ans.size() > n-1) ans.pop_back();
		assert((int) ans.size() == n - 1);
		for(auto p : ans) {
			std::cout << p.first + 1 << ' ' << p.second + 1 << '\n';
		}
	}
}