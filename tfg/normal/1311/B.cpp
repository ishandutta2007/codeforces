#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n, m;
		std::cin >> n >> m;
		std::vector<int> a(n);
		std::vector<bool> b(n, false);
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		auto want = a;
		std::sort(want.begin(), want.end());
		while(m--) {
			int x;
			std::cin >> x;
			b[x-1] = true;
		}
		for(int l = 0, r = 0; l < n; l = r) {
			while(r < n && b[l] == b[r]) r++;
			if(b[l]) {
				std::sort(a.begin() + l, a.begin() + r + 1);
			}
		}
		if(want == a) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}