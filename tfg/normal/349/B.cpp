#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int cost[10];
	int v;
	std::cin >> v;
	int mn = 1e9;
	for(int i = 1; i <= 9; i++) {
		std::cin >> cost[i];
		mn = std::min(mn, cost[i]);
	}
	std::string ans;
	while(v >= mn) {
		int mx = -1;
		int wtf = -1;
		for(int i = 9; i >= 1; i--) {
			if((v - cost[i]) / mn > mx && (v - cost[i]) >= 0) {
				mx = (v - cost[i]) / mn;
				wtf = i;
			}
		}
		ans += char('0' + wtf);
		v -= cost[wtf];
	}
	if(ans.empty()) {
		ans = "-1";
	}
	std::cout << ans << std::endl;
}