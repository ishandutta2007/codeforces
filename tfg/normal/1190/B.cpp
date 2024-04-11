#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	int pos = -1;
	for(int i = 0; i+1 < n; i++) {
		if(a[i] == a[i+1]) {
			if(pos != -1) {
				std::cout << "cslnb\n";
				return 0;
			}
			pos = i;
		}
	}
	int turn = 0;
	if(pos >= 0) {
		if((pos > 0 && a[pos-1] == a[pos]-1) || a[pos] == 0) {
			std::cout << "cslnb\n";
			return 0;
		}
		turn ^= 1;
		a[pos]--;
	}
	for(int i = 0; i < n; i++) {
		turn ^= (a[i]-i)&1;
	}
	std::cout << (turn ? "sjfnb\n" : "cslnb\n");
}