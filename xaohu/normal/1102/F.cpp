#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int n, m, a[16][10000];
int dp[1 << 16][16];
int min1[16][16], min2[16][16];

int solve(int mask, int x) {
	if (dp[mask][x] != -1)
		return dp[mask][x];
	dp[mask][x] = 0;
	for (int bit = 0; bit < n; bit++)
		if (bit != x && (mask >> bit & 1))
			dp[mask][x] = max(dp[mask][x], min(min1[x][bit], solve((mask ^ (1 << x)), bit)));
	return dp[mask][x];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			cin >> a[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			min1[i][j] = min2[i][j] = 1e9;

			for (int k = 0; k < m; k++)
				min1[i][j] = min(min1[i][j], abs(a[i][k] - a[j][k]));

			for (int k = 0; k + 1 < m; k++)
				min2[i][j] = min(min2[i][j], abs(a[i][k] - a[j][k + 1]));
		}

	int res = 0;
	for (int i = 0; i < n; i++) {
		memset(dp, -1, sizeof dp);
		for (int j = 0; j < n; j++)
			dp[1 << j][j] = (i == j ? 1e9 : 0);

		for (int j = 0; j < n; j++) {
			res = max(res, min(min2[j][i], solve((1 << n) - 1, j)));
		}
	}

	cout << res << endl;

	return 0;
}