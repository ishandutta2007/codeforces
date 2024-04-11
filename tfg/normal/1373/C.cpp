#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	std::string str;
	std::cin >> str;
	long long ans = 0;
	int cur = 0, sum = -1;
	for(int i = 0; 1; i++) {
		sum++;
		while(cur < (int) str.size() && sum >= 0) {
			sum += str[cur++] == '+' ? 1 : -1;
		}
		ans += cur;
		if(sum >= 0) break;
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}