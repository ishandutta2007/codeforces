#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> dp(m + 1, 0);
	while(n--) {
		int s;
		std::cin >> s;
		std::vector<int> sum(s + 1, 0);
		for(int i = 1; i <= s; i++) {
			std::cin >> sum[i];
			sum[i] += sum[i - 1];
		}
		std::vector<int> trans(s + 1, 0);
		for(int l = 0; l <= s; l++) {
			for(int r = l; r <= s; r++) {
				trans[l + s - r] = std::max(trans[l + s - r], sum[l] + sum[s] - sum[r]);
			}
		}
		for(int i = 1; i <= s; i++) {
			trans[i] = std::max(trans[i], trans[i - 1]);
		}
		for(int i = m; i > 0; i--) {
			for(int j = 1; j <= i && j <= s; j++) {
				dp[i] = std::max(dp[i], dp[i - j] + trans[j]);
			}
		}
	}
	std::cout << dp[m] << std::endl;
}