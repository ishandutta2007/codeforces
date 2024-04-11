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
		std::vector<int> a(n, 0);
		for(int i = 0; i < n; i++) {
			int x;
			std::cin >> x;
			x--;
			a[x]++;
		}
		std::vector<int> b(n+1, 0);
		for(int i = 0; i < n; i++) {
			if(a[i] > 1) {
				b[a[i]]++;
			}
		}
		int f = n;
		while(f > 0 && b[f] == 0) f--;
		assert(f);
		int ans = 1;
		while(ans < n) {
			int groups = (n + ans) / ans;
			int good = n % ans;
			//int bad = ans - good;
			if(f < groups) {
				ans++;
				continue;
			}
			if(f > groups) {
				break;
			}
			//std::cout << "trying " << ans << " with " << good << " goods, groups is " << groups << "\n";
			assert(f == groups);
			if(good < b[f]) {
				break;
			}
			ans++;
		}
		std::cout << std::max(ans-2, 0) << '\n';
	}
}