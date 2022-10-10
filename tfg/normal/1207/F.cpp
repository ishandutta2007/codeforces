#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 500500;
const int bs = (int) sqrt(ms) + 1;

int a[ms], b[bs][bs];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int q;
	std::cin >> q;
	while(q--) {
		int t, x, y;
		std::cin >> t >> x >> y;
		if(t == 1) {
			a[x] += y;
			for(int i = 1; i < bs; i++) {
				b[i][x % i] += y;
			}
		} else {
			int ans = 0;
			if(x < bs) {
				ans = b[x][y];
			} else {
				for(int i = y; i < ms; i += x) {
					ans += a[i];
				}
			}
			std::cout << ans << '\n';
		}
	}
}