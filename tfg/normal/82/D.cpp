#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 3030;

int memo[ms][ms];
int cost[ms];
std::pair<int, int> to[ms][ms];
std::pair<int, int> got[ms][ms];
int n;
int dp(int l, int on) {
	int &ans = memo[l][on];
	if(ans != -1) return ans;
	ans = 0;
	if(l == n) return ans;
	ans = 2e9;
	int rest = n - on + 1;
	if(rest == 1) {
		to[l][on] = {n, n};
		ans = cost[l];
		got[l][on] = {l, -1};
	} else if(rest == 2) {
		to[l][on] = {n, n};
		ans = std::max(cost[l], cost[on]);
		got[l][on] = {l, on};
	} else {
		// getting l and on
		{
			int cur = std::max(cost[l], cost[on]) + dp(on+1, on+2);
			if(cur < ans) {
				ans = cur;
				to[l][on] = {on+1, on+2};
				got[l][on] = {l, on};
			}
		}
		// getting l and on+1
		{
			int cur = std::max(cost[l], cost[on+1]) + dp(on, on+2);
			if(cur < ans) {
				ans = cur;
				to[l][on] = {on, on+2};
				got[l][on] = {l, on+1};
			}
		}
		// getting l and on+1
		{
			int cur = std::max(cost[on], cost[on+1]) + dp(l, on+2);
			if(cur < ans) {
				ans = cur;
				to[l][on] = {l, on+2};
				got[l][on] = {on, on+1};
			}
		}
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	memset(memo, -1, sizeof memo);
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> cost[i];
	}
	std::cout << dp(0, 1) << std::endl;
	for(int l = 0, on = 1; l != n; ) {
		//std::cout << "(" << l << ", " << on << ")\n";
		auto nxt = to[l][on];
		std::cout << got[l][on].first + 1;
		if(got[l][on].second == -1) {
			std::cout << '\n';
		} else {
			std::cout << ' ' << got[l][on].second + 1 << '\n';
		}
		l = nxt.first;
		on = nxt.second;
	}
}