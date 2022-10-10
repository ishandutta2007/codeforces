#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1001000;

int par[ms], best[ms];

int getPar(int x) { return par[x] == x ? x : par[x] = getPar(par[x]); }
void makeUnion(int a, int b) {
	a = getPar(a), b = getPar(b);
	if(a > b) std::swap(a, b);
	par[a] = b;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::string str;
	std::cin >> n >> str;
	int dp[2] = {0, 0};
	for(int i = 0; i < n; i++) {
		par[i] = i;
		if(str[i] == '?') {
			dp[1]++;
			dp[0]++;
		} else if(str[i] == '1') {
			dp[1]++;
			dp[0] = 0;
		} else {
			dp[0]++;
			dp[1] = 0;
		}
		best[i] = std::max(dp[0], dp[1]);
	}
	par[n] = n;
	for(int jump = 1; jump <= n; jump++) {
		int ans = 0;
		for(int on = 0; on < n; ) {
			on += jump - 1;
			while(on < n && best[on] < jump) {
				makeUnion(on, on+1);
				on = getPar(on);
			}
			if(on >= n) {
				break;
			}
			ans++;
			on++;
		}
		std::cout << ans << (jump == n ? '\n' : ' ');
	}
}