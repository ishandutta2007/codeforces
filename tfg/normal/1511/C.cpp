#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, q;
	std::cin >> n >> q;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	while(q--) {
		int val;
		std::cin >> val;
		int pos = 0;
		while(a[pos] != val) pos++;
		std::cout << pos+1 << '\n';
		for(int i = pos-1; i >= 0; i--) {
			std::swap(a[i], a[i+1]);
		}
	}
}