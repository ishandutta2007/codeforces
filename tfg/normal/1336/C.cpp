#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 3030;
const int MOD = 998244353;

int n, m;
std::string s, t;
int memo[3][ms][ms];

int dp(int l, int r, int on) {
	int &ans = (l >= 0 && r < m ? memo[0][l][r] : (l == -1 ? memo[1][r][on] : memo[2][l][on]));
	/*if(l >= 0 && r < m) {
		ans = memo[0][l][r];
	} else if(l == -1) {
		ans = memo[1][r][on];
	} else {
		ans = memo[2][l][on];
	}*/
	if(ans != -1) return ans;
	ans = 0;
	if(l == -1 && r == m) ans = 1;
	// base case
	if(on == n) {
		//std::cout << "at (" << l << ", " << r << ", " << on << ") got " << ans << '\n';
		return ans;
	}
	// getting putting on left
	if(l != -1 && s[on] == t[l]) {
		ans = (ans + dp(l-1, r, on+1)) % MOD;
	}
	if(l == m-1 && r == m) {
		ans = (ans + dp(l, r, on+1)) % MOD;
	}
	// getting putting on right
	if(r == m || t[r] == s[on]) {
		ans = (ans + dp(l, std::min(r+1, m), on+1)) % MOD;
	}
	//std::cout << "at (" << l << ", " << r << ", " << on << ") got " << ans << '\n';
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> s >> t;
	n = (int) s.size();
	m = (int) t.size();
	memset(memo, -1, sizeof memo);
	int ans = 0;
	for(int i = 0; i <= m; i++) {
		ans = (ans + dp(i-1, i, 0)) % MOD;
	}
	for(int i = 1; i < n; i++) {
		//ans = (ans + dp(m-1, m, 0)) % MOD;
	}
	std::cout << ans << '\n';
}