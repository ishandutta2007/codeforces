#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> mask(n, 0);
	std::vector<int> ans(n, -1);
	std::vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		a[i]--;
	}
	for(int i = 0; i < n; i++) {
		std::cin >> b[i];
		b[i]--;
	}
	int c = 0;
	int tot = 0;
	for(int i = 0, j = 0; i < n; c++) {
		c = std::min(c, k-1);
		assert(i == j);
		while(1) {
			ans[a[i]] = ans[b[i]] = c;
			mask[a[i++]] |= 1;
			if(mask[a[i-1]] == 3) tot++;
			mask[b[j++]] |= 2;
			if(mask[b[j-1]] == 3) tot++;
			if(tot == i) break;
		}
	}
	if(c >= k) {
		std::cout << "YES\n";
		for(int i = 0; i < n; i++) {
			std::cout << char('a' + ans[i]);
		}
		std::cout << '\n';
	} else {
		std::cout << "NO\n";
	}
}