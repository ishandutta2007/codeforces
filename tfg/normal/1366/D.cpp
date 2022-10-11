#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1e7 + 10;

int prime[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 2; i < ms; i++) {
		if(prime[i] != 0) continue;
		for(int j = i; j < ms; j += i) {
			prime[j] = i;
		}
	}
	int n;
	std::cin >> n;
	std::vector<int> a(n, -1), b(n, -1);
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		int y = 1;
		int p = prime[x];
		while(x % p == 0) {
			x /= p;
			y *= p;
		}
		if(x != 1 && y != 1) {
			a[i] = x;
			b[i] = y;
		}
	}
	for(int i = 0; i < n; i++) {
		std::cout << a[i] << (i + 1 == n ? '\n' : ' ');
	}
	for(int i = 0; i < n; i++) {
		std::cout << b[i] << (i + 1 == n ? '\n' : ' ');
	}
}