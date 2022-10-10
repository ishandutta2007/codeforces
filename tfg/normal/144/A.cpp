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
	int mn[2] = {0, a[0]};
	int mx[2] = {0, a[0]};
	for(int i = 1; i < n; i++) {
		if(a[i] > mx[1]) {
			mx[1] = a[i];
			mx[0] = i;
		}
		if(a[i] <= mn[1]) {
			mn[1] = a[i];
			mn[0] = i;
		}
	}
	std::cout << mx[0] + n - mn[0] - 1 - (mn[0] < mx[0] ? 1 : 0) << '\n';
}