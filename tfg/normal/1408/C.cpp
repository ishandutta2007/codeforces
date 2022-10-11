#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <iomanip>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int tt;
	std::cin >> tt;
	std::cout << std::fixed << std::setprecision(10);
	while(tt--) {
		int n, len;
		std::cin >> n >> len;
		std::vector<int> a(n);
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		double ans = 0;
		double pos[2];
		pos[0] = 0, pos[1] = len;
		for(int l = 0, r = n-1; 1; ) {
			// std::cout << "at (" << l << ", " << r << ") with time " << ans << '\n';
			if(l > r) {
				ans += (pos[1] - pos[0]) / (1 + l + (n - r));
				break;
			}
			if((a[l] - pos[0]) / (1 + l) <= (pos[1] - a[r]) / (n - r)) {
				double t = (a[l] - pos[0]) / (1 + l);
				pos[0] = a[l++];
				pos[1] -= (n - r) * t;
				ans += t;
			} else {
				double t = (pos[1] - a[r]) / (n - r);
				pos[1] = a[r--];
				pos[0] += (1 + l) * t;
				ans += t;
			}
		}
		std::cout << ans << '\n';
	}
}