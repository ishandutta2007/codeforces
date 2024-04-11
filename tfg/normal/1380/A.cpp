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
		std::vector<int> a(n);
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		int l = 0, r = n-1;
		while(l <= r) {
			if(a[l] == r-l+1) l++;
			else if(a[r] == r-l+1) r--;
			else {
				break;
			}
		}
		if(l < r) {
			int i = 0;
			while(a[i] != r-l+1) i++;
			assert(l < i && i < r);
			std::cout << "YES\n" << l+1 << ' ' << i+1 << ' ' << r+1 << '\n';
		} else {
			std::cout << "NO\n";
		}
	}
}