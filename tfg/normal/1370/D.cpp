#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

int n;
int a[ms], want;
int memo[ms][2];
int dp(int on, int t) {
	int &ans = memo[on][t];
	if(ans != -1) return ans;
	ans = 0;
	if(on == n) return ans;
	ans = dp(on+1, t);
	if(t == 1) ans = std::max(ans, 1 + dp(on+1, 1-t));
	else if(a[on] <= want) ans = std::max(ans, 1 + dp(on+1, 1-t));
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int k;
	std::cin >> n >> k;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int l = 0, r = 1e9 + 1;
	auto check = [&](int x) {
		want = x;
		memset(memo, -1, sizeof memo);
		return std::max(dp(0, 0), dp(0, 1));
	};
	while(l != r) {
		int mid = (l + r) / 2;
		if(check(mid) >= k) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	std::cout << l << '\n';
}