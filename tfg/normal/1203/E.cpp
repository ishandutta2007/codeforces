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
	for(auto &v : a) {
		std::cin >> v;
	}
	std::sort(a.begin(), a.end());
	int best = 0;
	int ans = 0;
	for(auto v : a) {
		for(int i = -1; i <= 1; i++) {
			if(v + i > best) {
				best = v + i;
				ans++;
				break;
			}
		}
	}
	std::cout << ans << '\n';
}