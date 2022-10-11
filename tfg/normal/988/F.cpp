#include <iostream>
#include <vector>

const int INF = 2e9 + 100;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int a, n, m;
	std::cin >> a >> n >> m;
	std::vector<int> rains(a + 1, 0);
	std::vector<std::vector<int>> dp, umbrella;
	std::vector<int> cost(m);
	dp.assign(a + 1, std::vector<int>(m + 1, INF));
	umbrella.resize(a + 1);
	for(int i = 0; i < n; i++) {
		int l, r;
		std::cin >> l >> r;
		rains[l]++;
		rains[r]--;
	}
	for(int i = 0; i < m; i++) {
		int pos;
		std::cin >> pos >> cost[i];
		umbrella[pos].push_back(i);
	}
	dp[0][m] = 0;
	for(int i = 0, s = 0; i < a; i++) {
		s += rains[i];
		for(int j = 0; j < m; j++) {
			dp[i][m] = std::min(dp[i][m], dp[i][j]);
		}
		for(auto u : umbrella[i]) {
			dp[i][u] = dp[i][m];
		}
		for(int j = 0; j < m; j++) {
			dp[i + 1][j] = std::min(INF, dp[i][j] + cost[j]);
		}
		if(s == 0) {
			dp[i+1][m] = dp[i][m];
		}
	}
	for(int i = 0; i < m; i++) {
		dp[a][m] = std::min(dp[a][m], dp[a][i]);
	}
	if(dp[a][m] >= INF) {
		dp[a][m] = -1;
	}
	/*for(int i = 0; i <= a; i++) {
		for(int j = 0; j <= m; j++) {
			std::cout << dp[i][j] << (j == m ? '\n' : ' ');
		}
	}*/
	std::cout << dp[a][m] << std::endl;
}