#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long pairs(long long x) { return x * (x - 1) / 2; }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		long long sum;
		std::cin >> sum;
		int on = 0;
		while(pairs(on+1) <= sum) {
			on++;
		}
		std::vector<int> want(on+1, 0);
		while(sum > 0) {
			while(pairs(on) > sum) on--;
			want[on]++;
			sum -= pairs(on);
		}
		std::string ans;
		for(int i = (int) want.size()-1; i > 0; i--) {
			while(want[i]--) {
				ans += '1';
			}
			ans += '3';
		}
		ans += '7';
		std::cout << ans << '\n';
	}
}