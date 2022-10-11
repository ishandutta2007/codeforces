#include <iostream>
#include <vector>

const int ms = 5050;
const int INF = 1e9;

int right[ms][ms / 2], mid[ms][ms / 2], dp[ms][ms / 2];
int a[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	int k = (n + 1) / 2;
	for(int i = 2; i <= k; i++) {
		dp[1][i] = right[1][i] = mid[1][i] = INF;
	}
	dp[1][1] = mid[1][0] = right[1][0] = right[1][1] = INF;
	for(int i = 2; i <= n; i++) {
		right[i][0] = mid[i][0] = INF;
		// from right to normal
		{
			for(int j = 0; j <= k; j++) {
				dp[i][j] = std::min(dp[i-1][j], right[i-1][j]);
			}
		}
		// from right to mid
		{
			int cost = std::max(0, std::min(a[i - 2] - 1, a[i - 1]) - a[i] + 1);
			for(int j = 1; j <= k; j++) {
				mid[i][j] = right[i-1][j-1] + cost;
			}
		}
		// from normal to mid
		{
			int cost = std::max(0, a[i-1] - a[i] + 1);
			for(int j = 1; j <= k; j++) {
				mid[i][j] = std::min(mid[i][j], dp[i-1][j-1] + cost);
			}
		}
		// from mid to right
		{
			int cost = std::max(0, a[i] - a[i-1] + 1);
			for(int j = 1; j <= k; j++) {
				right[i][j] = mid[i-1][j] + cost;
			}
		}
	}
	for(int i = 0; i <= n; i++) {
		break;
		for(int j = 0; j <= k; j++) {
			std::cout << "(" << dp[i][j] << ", " << right[i][j] << ", " << mid[i][j] << ") ";
		}
		std::cout << std::endl;
	}
	for(int i = 1; i <= k; i++) {
		dp[n][i] = std::min(dp[n][i], std::min(right[n][i], mid[n][i]));
		std::cout << dp[n][i] << (i == k ? '\n' : ' ');
	}
}