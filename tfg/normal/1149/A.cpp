#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	int par = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		par = (a[i] + par) % 2;
	}
	std::sort(a.begin(), a.end());
	if(par == 0 && a[0] == 1) {
		std::swap(a[0], a.back());
	}
	if(par == 1) {
		int fi = 0;
		while(fi < n && a[fi] == 1) fi++;
		if(fi < n) {
			std::swap(a[fi], a[0]);
		}
	}
	for(int i = 0; i < n; i++) {
		std::cout << a[i] << (i + 1 == n ? '\n' : ' ');
	}
}