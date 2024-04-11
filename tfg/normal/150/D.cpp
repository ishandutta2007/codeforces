#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 155;
const int INF = 1e8;

std::string str;
int cost[ms];
int memo[ms][ms][ms];
bool visit[ms][ms][ms];
int dp(int l, int r, int v) {
	if(l > r) return v == 0 ? -INF : cost[v - 1];
	int &ans = memo[l][r][v];
	if(visit[l][r][v]) return ans;
	ans = -INF;
	visit[l][r][v] = true;
	if(str[l] == str[r]) {
		ans = std::max(ans, dp(l+1, r-1, v + (l != r ? 2 : 1)));
	}
	if(v) {
		ans = std::max(ans, dp(l, r, 0) + cost[v - 1]);
	}
	for(int i = l + 1; i <= r; i++) {
		ans = std::max(ans, dp(l, i - 1, 0) + dp(i, r, v));
	}
	for(int i = l; i < r; i++) {
		ans = std::max(ans, dp(l, i, v) + dp(i + 1, r, 0));
	}
	if(ans < 0) ans = -INF;
	//std::cout << "dp(" << l << ", " << r << ", " << v << ") == " << ans << "\n";
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> cost[i];
		if(cost[i] == -1) cost[i] = -INF;
	}
	std::cin >> str;
	std::vector<int> ans(n + 1, -INF);
	ans[0] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			ans[j + 1] = std::max(ans[j + 1], ans[i] + std::max(0, dp(i, j, 0)));
		}
	}
	std::cout << ans[n] << '\n';
}