#include <iostream>
#define int long long
#include <cstring>

using namespace std;

const int MAX_N = 1e6 + 7, K = 21, M = 1e9 + 7;
int n;
signed dp[MAX_N][K][2];

int get(int x) {
	if (x > n) return 0;
	return (n / x);
}

signed main() {
	memset(dp, 0, sizeof(dp));
	//freopen("Desktop/input.txt", "r", stdin);
	cin >> n;
	int poww = 0, cur = 1;
	while (cur * 2 <= n) {
		cur *= 2;
		poww++;
	}
	dp[1][poww][0] = 1;
	if ((cur / 2) * 3 <= n) dp[1][poww - 1][1] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= poww; j++) {
			for (int k = 0; k <= 1; k++) {
				int t = 1;
				if (k == 1) t = 3;
				dp[i + 1][j][k] = (dp[i + 1][j][k] + dp[i][j][k] * (get((1 << j) * t) - i)) % M;
				if (j > 0) dp[i + 1][j - 1][k] = (dp[i + 1][j - 1][k] + dp[i][j][k] * (get((1 << (j - 1)) * t) - get((1 << j) * t))) % M; 
				if (k == 1) dp[i + 1][j][0] = (dp[i + 1][j][0] + dp[i][j][k] * (get(1 << j) - get((1 << j) * t))) % M;
			}
		}
	}
	cout << dp[n][0][0] << endl;
	return 0;
}