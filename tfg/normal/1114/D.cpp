#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 5050;

std::vector<int> b;
int memo[ms][ms];

int dp(int l, int r) {
	if(l == 0 && r-1 == (int) b.size()) return 0;
	int &ans = memo[l][r];
	if(ans != -1) return ans;
	ans = 1e9;
	if(l > 0) {
		ans = std::min(ans, 1 + dp(l-1, r));
	}
	if(r-1 < (int) b.size()) {
		ans = std::min(ans, 1 + dp(l, r+1));
	}
	if(l > 0 && r-1 < (int) b.size() && b[l-1] == b[r-1]) {
		ans = std::min(ans, 1 + dp(l-1, r+1));
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int last;
	std::cin >> last;
	for(int i = 1; i < n; i++) {
		int nxt;
		std::cin >> nxt;
		if(nxt != last) {
			b.push_back(last);
		}
		last = nxt;
	}
	b.push_back(last);
	memset(memo, -1, sizeof memo);
	int ans = 1e9;
	for(int i = 0; i < (int) b.size(); i++) {
		ans = std::min(ans, dp(i, i + 2));
	}
	std::cout << ans << '\n';
}