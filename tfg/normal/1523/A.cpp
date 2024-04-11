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
		std::string ans;
		int n, step;
		std::cin >> n >> step >> ans;
		while(step > 0) {
			step--;
			bool run = false;
			auto nxt = ans;
			for(int i = 0; i < n; i++) {
				if(ans[i] == '0' && (i > 0 && ans[i-1] == '1') + (i+1 < n && ans[i+1] == '1') == 1) {
					run = true;
					nxt[i] = '1';
				}
			}
			ans = nxt;
			if(!run) {
				step = 0;
			}
		}
		std::cout << ans << '\n';
	}
}