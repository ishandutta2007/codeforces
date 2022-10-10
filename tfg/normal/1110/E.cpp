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
	std::vector<long long> sum(n + 1, 0);
	std::vector<long long> a(n), b(n), c, d;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(i) {
			c.push_back(a[i] - a[i-1]);
		}
	}
	for(int i = 0; i < n; i++) {
		std::cin >> b[i];
		if(i) {
			d.push_back(b[i] - b[i-1]);
		}
	}
	std::sort(c.begin(), c.end());
	std::sort(d.begin(), d.end());
	std::cout << (c == d && a[0] == b[0] && a[n-1] == b[n-1] ? "Yes\n" : "No\n");
}