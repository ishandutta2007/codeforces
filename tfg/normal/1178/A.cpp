#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int sum = 0;
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	int tot = 0;
	int got = 0;
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		a[i] = x;
		if(i == 0 || a[0] >= a[i] * 2) {
			sum += x;
			got++;
		}
		tot += x;
	}
	if(sum > tot / 2) {
		std::cout << std::min(got, n-1) << '\n';
		for(int i = 0; i < n - (got == n); i++) {
			if(i == 0 || a[0] >= a[i] * 2) {
				std::cout << i + 1 << ' ';
			}
		}
	} else {
		std::cout << "0\n";
	}
}