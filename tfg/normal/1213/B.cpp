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
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		int got = 1e9;
		int ans = 0;
		for(int i = 0; i < n; i++) {
			int x = a[n-i-1];
			if(got < x) {
				ans++;
			} else {
				got = x;
			}
		}
		std::cout << ans << '\n';
	}
}