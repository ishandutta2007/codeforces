#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1010;

int a[ms], b[ms], c[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		std::cin >> b[i];
	}
	for(int i = 0; i < n; i++) {
		c[i] = n - (a[i] + b[i]);
	}
	for(int i = 0; i < n; i++) {
		int v = 0;
		for(int j = 0; j < i; j++) {
			if(c[j] > c[i]) v++;
		}
		if(v != a[i]) {
			std::cout << "NO\n";
			return 0;
		}
		v = 0;
		for(int j = i + 1; j < n; j++) {
			if(c[j] > c[i]) v++;
		}
		if(v != b[i]) {
			std::cout << "NO\n";
			return 0;
		}
	}
	std::cout << "YES\n";
	for(int i = 0; i < n; i++) {
		std::cout << c[i] << (i + 1 == n ? '\n' : ' ');
	}
}