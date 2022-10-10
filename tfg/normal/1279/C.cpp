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
		int n, m;
		std::cin >> n >> m;
		int mx = -1;
		std::vector<int> a(n);
		for(int i = 0; i < n; i++) {
			int x;
			std::cin >> x;
			x--;
			a[x] = i;
		}
		long long ans = 0;
		int used = 0;
		while(m--) {
			int x;
			std::cin >> x;
			x--;
			if(mx > a[x]) {
				ans++;
			} else {
				ans += 2 * (a[x] - used) + 1;
				mx = a[x];
			}
			used++;
		}
		//ans += mx;
		std::cout << ans << '\n';
	}
}