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
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int got = 1;
		for(int j = 0; j < i; j++) {
			if(a[i] % a[j] == 0) {
				got = 0;
			}
		}
		ans += got;
	}
	std::cout << ans << '\n';
}