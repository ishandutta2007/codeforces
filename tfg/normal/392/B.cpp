#include <iostream>

typedef long long ll;

ll cost[3][3];
ll dp[44][3][3];

int main() {
	int n;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			std::cin >> cost[i][j];
		}
	}
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		int v[3];
		v[0] = 0;
		v[1] = 1;
		v[2] = 2;
		dp[i][0][1] = std::min(dp[i - 1][v[0]][v[2]] + cost[v[0]][v[1]] + dp[i - 1][v[2]][v[1]],
							   dp[i - 1][v[0]][v[1]] + cost[v[0]][v[2]] + dp[i - 1][v[1]][v[0]] + cost[v[2]][v[1]] + dp[i - 1][v[0]][v[1]]);
		std::swap(v[1], v[2]);
		dp[i][0][2] = std::min(dp[i - 1][v[0]][v[2]] + cost[v[0]][v[1]] + dp[i - 1][v[2]][v[1]],
							   dp[i - 1][v[0]][v[1]] + cost[v[0]][v[2]] + dp[i - 1][v[1]][v[0]] + cost[v[2]][v[1]] + dp[i - 1][v[0]][v[1]]);
		v[0] = 1;
		v[1] = 0;
		v[2] = 2;
		dp[i][1][0] = std::min(dp[i - 1][v[0]][v[2]] + cost[v[0]][v[1]] + dp[i - 1][v[2]][v[1]],
							   dp[i - 1][v[0]][v[1]] + cost[v[0]][v[2]] + dp[i - 1][v[1]][v[0]] + cost[v[2]][v[1]] + dp[i - 1][v[0]][v[1]]);
		std::swap(v[1], v[2]);
		dp[i][1][2] = std::min(dp[i - 1][v[0]][v[2]] + cost[v[0]][v[1]] + dp[i - 1][v[2]][v[1]],
							   dp[i - 1][v[0]][v[1]] + cost[v[0]][v[2]] + dp[i - 1][v[1]][v[0]] + cost[v[2]][v[1]] + dp[i - 1][v[0]][v[1]]);
		v[0] = 2;
		v[1] = 0;
		v[2] = 1;
		dp[i][2][0] = std::min(dp[i - 1][v[0]][v[2]] + cost[v[0]][v[1]] + dp[i - 1][v[2]][v[1]],
							   dp[i - 1][v[0]][v[1]] + cost[v[0]][v[2]] + dp[i - 1][v[1]][v[0]] + cost[v[2]][v[1]] + dp[i - 1][v[0]][v[1]]);
		std::swap(v[1], v[2]);
		dp[i][2][1] = std::min(dp[i - 1][v[0]][v[2]] + cost[v[0]][v[1]] + dp[i - 1][v[2]][v[1]],
							   dp[i - 1][v[0]][v[1]] + cost[v[0]][v[2]] + dp[i - 1][v[1]][v[0]] + cost[v[2]][v[1]] + dp[i - 1][v[0]][v[1]]);
	}
	std::cout << dp[n][0][2] << '\n';
}