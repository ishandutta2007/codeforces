#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	if(n == 2) {
		std::cout << "-1\n";
		return 0;
	} else if(n == 1) {
		std::cout << "1\n";
		return 0;
	}
	std::vector<int> a(n, -1);
	int l = 0, r = n;
	while(r - l >= 4) {
		a[l] = l + 1;
		a[l+1] = r - 1;
		a[r-1] = r - 2;
		a[r-2] = l;
		l += 2;
		r -= 2;
	}
	if(r - l == 1) {
		a[l] = l;
	} else if(r - l > 1) {
		std::cout << "-1\n";
		return 0;
	}
	for(int i = 0; i < n; i++) {
		std::cout << a[i] + 1 << (i + 1 == n ? '\n' : ' ');
	}
}