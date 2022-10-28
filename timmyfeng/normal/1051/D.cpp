#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e3 + 1;
const int M = (119 << 23) + 1;
const int DELTA[4][4] = {
	{0, 1, 1, 1},
	{0, 0, 2, 0},
	{0, 2, 0, 0},
	{1, 1, 1, 0}
};

int dp[MX][2 * MX][4];

int add(int a, int b) {
	a += b;
	return a < M ? a : a - M;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;

	dp[1][1][0] = dp[1][2][1] = dp[1][2][2] = dp[1][1][3] = 1;
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < 2 * n; ++j) {
			for (int k = 0; k < 4; ++k) {
				for (int l = 0; l < 4; ++l) {
					int cnt = j + DELTA[k][l];
					dp[i + 1][cnt][l] = add(dp[i + 1][cnt][l], dp[i][j][k]);
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 4; ++i) {
		ans = add(ans, dp[n][k][i]);
	}
	cout << ans << '\n';
}