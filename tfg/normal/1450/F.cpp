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
		std::vector<int> b(n, 0);
		int last = -1;
		int mx = 0;
		int ans = 0;
		for(int i = 0; i < n; i++) {
			int x;
			std::cin >> x;
			x--;
			if(i == 0) {
				b[x]++;
			}
			if(x == last) {
				b[x] += 2;
			}
			if(x == last) ans++;
			last = x;
			a[x]++;
			mx = std::max(mx, a[x]);
		}
		b[last]++;
		int o = 0;
		for(int i = 0; i < n; i++) {
			o = std::max(o, b[i]);
		}
		std::cout << ((n+1)/2 < mx ? -1 : ans + std::max(0, o - (ans+2))) << '\n';
	}
}