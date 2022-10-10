#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		std::pair<int, int> ans(-1, -1);
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
			if(i && abs(a[i] - a[i-1]) > 1) {
				ans = std::pair<int, int>(i, i+1);
			}
		}
		if(ans.first == -1) {
			std::cout << "NO\n";
		} else {
			std::cout << "YES\n";
			std::cout << ans.first << ' ' << ans.second << '\n';
		}
	}
}