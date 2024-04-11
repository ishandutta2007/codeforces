#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

int f[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int mn = 1e9;
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		mn = std::min(mn, a[i]);
	}
	for(int i = 0; i < n; i++) {
		a[i] = a[i] - mn + 1;
		if(a[i] < ms) {
			f[a[i]]++;
		}
	}
	for(int i = 1, step = 0; step < n; step++) {
		assert(f[i]);
		f[i]--;
		if(f[i+1]) {
			i++;
		} else if(f[i-1]) {
			i--;
		} else if(step + 1 == n && i == 2) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
			return 0;
		}
	}
}