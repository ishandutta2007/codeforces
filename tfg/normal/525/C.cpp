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
	int last = 0;
	long long ans = 0;
	std::sort(a.rbegin(), a.rend());
	for(int i = 0; i+1 < n; i++) {
		if(a[i] == a[i+1] || a[i] - 1 == a[i+1]) {
			if(last) ans += (long long) last * a[i+1], last = 0;
			else last = a[i+1];
			i++;
		}
	}
	std::cout << ans << '\n';
}