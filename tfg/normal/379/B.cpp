#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	while(a[0] > 0) {
		std::cout << "PRL";
		a[0]--;
	}
	for(int i = 1; i < n; i++) {
		std::cout << 'R';
		if(a[i]) {
			a[i]--;
			std::cout << 'P';
		}
	}
	while(a[n-1] > 0) {
		std::cout << "LRP";
		a[n-1]--;
	}
	for(int rep = 0; rep < 300; rep++) {
		if(rep % 2 == 0) {
			for(int i = n-2; i >= 0; i--) {
				std::cout << 'L';
				if(a[i]) {
					a[i]--;
					std::cout << 'P';
				}
			}
		} else {
			for(int i = 1; i < n; i++) {
				std::cout << 'R';
				if(a[i]) {
					a[i]--;
					std::cout << 'P';
				}
			}
		}
	}
}