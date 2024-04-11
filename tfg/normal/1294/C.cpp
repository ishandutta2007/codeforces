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
		int n;
		std::cin >> n;
		std::vector<int> divs;
		for(int i = 2; i * i <= n; i++) {
			if(n % i == 0) {
				divs.push_back(i);
				if(n / i != i) {
					divs.push_back(n / i);
				}
			}
		}
		int a = -1, b, c;
		for(auto i : divs) {
			for(auto j : divs) {
				int k = n / i / j;
				if(k * i * j == n && k != j && k != i && i != j && k != 1) {
					a = i, b = j, c = k;
					break;
				}
			}
			if(a != -1) break;
		}
		if(a != -1) {
			std::cout << "YES\n";
			std::cout << a << ' ' << b << ' ' << c << '\n';
		} else {
			std::cout << "NO\n";
		}
	}
}