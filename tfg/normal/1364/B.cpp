#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::vector<int> a;
		for(int i = 0; i < n; i++) {
			int x;
			std::cin >> x;
			while((int) a.size() > 1 && abs(a[(int) a.size() - 2] - a.back()) + abs(a.back() - x) == abs(a[(int) a.size() - 2] - x)) {
				a.pop_back();
			}
			a.push_back(x);
		}
		std::cout << a.size() << '\n';
		for(int i = 0; i < (int) a.size(); i++) {
			std::cout << a[i] << (i + 1 == (int) a.size() ? '\n' : ' ');
		}
	}
}