#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int g(int n) { return n == 0 ? 0 : n % 10 + g(n / 10); }
int f(int n) { return n + g(n); }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> ans;
	for(int i = n; i + 9 * 9 >= n && i > 0; i--) {
		if(f(i) == n) ans.push_back(i);
	}
	std::cout << ans.size() << '\n';
	for(int i = 0; i < (int) ans.size(); i++) {
		std::cout << ans[(int) ans.size() - i - 1] << (i + 1 == n ? '\n' : ' ');
	}
}