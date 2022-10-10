#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	const int INF = 1e9;
	// 0 == empty, 1 == [, 2 == [:, 3 == [::, 4 is finished
	int dp[] = {0, INF, INF, INF, INF};
	std::string str;
	std::cin >> str;
	for(auto v : str) {
		if(v == '[') {
			dp[1] = std::min(dp[0], dp[1] + 1);
			dp[0]++;
			dp[2]++;
			dp[3]++;
			dp[4]++;
		} else if(v == ':') {
			dp[3] = std::min(dp[2], dp[3] + 1);
			dp[2] = std::min(dp[1], dp[2] + 1);
			dp[0]++;
			dp[1]++;
			dp[4]++;
		} else if(v == '|') {
			dp[0]++;
			dp[1]++;
			dp[3]++;
			dp[4]++;
		} else if(v == ']') {
			dp[4] = std::min(dp[4] + 1, dp[3]);
			dp[3]++;
			dp[2]++;
			dp[1]++;
			dp[0]++;
		} else {
			dp[0]++;
			dp[1]++;
			dp[2]++;
			dp[3]++;
			dp[4]++;
		}
	}
	int ans = dp[4];
	if(ans >= INF) ans = -1;
	else ans = (int) str.size() - ans;
	std::cout << ans << '\n';
}