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
		int a, b, c;
		std::cin >> a >> b >> c;
		int ans[2] = {1, 1};
		bool flip = a < b;
		a--;b--;c--;
		if(flip) std::swap(a, b);
		for(int i = 0; i < c; i++) {
			ans[0] = ans[1] = ans[1] * 10;
		}
		int num = 1;
		for(int i = c; i < b; i++) {
			num *= 10;
		}
		int kek = 1;
		for(int i = b; i < a; i++) {
			kek *= 10;
		}
		ans[0] = ans[0] * (kek * num + 1);
		ans[1] = ans[1] * num;
		if(flip) std::swap(ans[0], ans[1]);
		std::cout << ans[0] << ' ' << ans[1] << '\n';
	}
}