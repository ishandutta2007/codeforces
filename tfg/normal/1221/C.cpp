#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int q;
	std::cin >> q;
	while(q--) {
		int a, b, c;
		std::cin >> a >> b >> c;
		int ans = std::min(a, std::min(b, c));
		a -= ans;
		b -= ans;
		c -= ans;
		if(a > 0 && b > 0) {
			if(a < b) std::swap(a, b);
			int l = 0, r = b;
			while(l != r) {
				int mid = (l + r + 1) / 2;
				if(a + b - 2 * mid < mid) {
					r = mid - 1;
				} else {
					l = mid;
				}
			}
			ans += l;
		}
		std::cout << ans << '\n';
	}
}