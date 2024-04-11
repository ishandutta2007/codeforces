#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

int f[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	int mx = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		f[a[i]]++;
		if(f[a[i]] > f[mx]) mx = a[i];
	}
	std::cout << n - f[mx] << '\n';
	int st = 0;
	while(a[st] != mx) st++;
	while(st > 0) {
		st--;
		if(a[st] > mx) {
			std::cout << "2 " << st + 1 << ' ' << st + 2 << '\n';
		} else {
			std::cout << "1 " << st + 1 << ' ' << st + 2 << '\n';
		}
		a[st] = mx;
	}
	for(int i = 0; i < n; i++) {
		if(a[i] > mx) {
			std::cout << "2 " << i + 1 << ' ' << i << '\n';
		} else if(a[i] < mx) {
			std::cout << "1 " << i + 1 << ' ' << i << '\n';
		}
	}
}