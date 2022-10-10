#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1001000;

int a[ms * 4];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int l = 0, r = n;
	for(int i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	for(int k = 2; k <= n; k++) {
		int last = a[l];
		for(int i = l + k; i < r; i += k) {
			std::swap(last, a[i]);
		}
		std::swap(last, a[r]);
		r++;
		l++;
	}
	for(int i = l; i < r; i++) {
		std::cout << a[i] << (i + 1 == r ? '\n' : ' ');
	}
}