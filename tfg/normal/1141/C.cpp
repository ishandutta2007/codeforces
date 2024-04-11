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
	std::vector<long long> a(n, 0);
	int pos = 0, neg = 0;
	for(int i = 1; i < n; i++) {
		std::cin >> a[i];
		a[i] += a[i - 1];
		if(a[i] > 0) {
			pos++;
		} else if(a[i] < 0) {
			neg++;
		} else {
			std::cout << "-1\n";
			return 0;
		}
	}
	a[0] = neg + 1;
	for(int i = 1; i < n; i++) {
		a[i] += a[0];
	}
	auto b = a;
	std::sort(b.begin(), b.end());
	b.resize(std::unique(b.begin(), b.end()) - b.begin());
	if((int) b.size() == n && b[0] == 1 && b[n-1] == n) {
		for(int i = 0; i < n; i++) {
			std::cout << a[i] << (i + 1 == n ? '\n' : ' ');
		}
	} else {
		std::cout << "-1\n";
	}
}