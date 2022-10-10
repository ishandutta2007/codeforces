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
	std::vector<int> d;
	for(int i = 1; i * i <= n; i++) {
		if(n % i == 0) {
			d.push_back(i);
			if(n / i != i) {
				d.push_back(n / i);
			}
		}
	}
	std::sort(d.begin(), d.end(), std::greater<int>());
	for(int i = 0; i < (int) d.size(); i++) {
		int vals = n / d[i];
		std::cout << (long long) vals * (vals - 1) / 2 * d[i] + vals << (i + 1 == (int) d.size() ? '\n' : ' ');
	}
}