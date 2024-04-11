#include <iostream>
#include <vector>
#include <cstring>

const int ms = 1010;

int n, p, k;

short a[ms], b[ms], c[ms];
short int memo[ms][ms][51][2];
short int dp(int on, int rest, int g, int t) {
	if(g == 0) t = 0;
	if(on > n) {
		return 0;
	}
	short int &ans = memo[on][rest][g][t];
	if(ans != -1) return ans;
	ans = 0;
	if(g > 0) {
		ans = dp(on+1, rest, g - 1, t);
		if(t == 0 && a[on]) ans++;
		else if(t == 1 && b[on]) ans++;
	} else {
		ans = dp(on+1, rest, 0, 0);
	}
	if(rest == 0) {
		//std::cout << "on (" << on << ", " << rest << ", " << g << ", " << t << ") middle " << ans << '\n';
		return ans;
	}
	if(g < k) {
		ans = std::max(ans, dp(on, rest-1, k, 0));
		ans = std::max(ans, dp(on, rest-1, k, 1));
	}
	// try to get
	if(g > 0) {
		int l = on - 1;
		int r = std::min(n, l + g);
		ans = std::max((int) ans, dp(r + 1, rest-1, k - g, t^1) + c[r] - c[l]);
	}
	//std::cout << "on (" << on << ", " << rest << ", " << g << ", " << t << ") returning " << ans << '\n';
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> p >> k;
	int s;
	std::cin >> s;
	while(s--) {
		int v;
		std::cin >> v;
		a[v] = 1;
	}
	std::cin >> s;
	while(s--) {
		int v;
		std::cin >> v;
		b[v] = 1;
	}
	for(int i = 1; i <= n; i++) {
		c[i] = (a[i] | b[i]) + c[i-1];
	}
	memset(memo, -1, sizeof memo);
	std::cout << dp(1, p, 0, 0) << '\n';
}