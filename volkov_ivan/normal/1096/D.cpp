#include <iostream>

using namespace std;

const long long MAX_N = 1e5 + 7, INF = 1e18;
long long dp[MAX_N][5];
long long a[MAX_N];
string key = "hard$";

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 5; j++) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			if (dp[i][j] == INF) continue;
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a[i]);
			if (s[i] != key[j]) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			else dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
		}
	}
	long long ans = INF;
	for (int i = 0; i < 4; i++) ans = min(ans, dp[n][i]);
	cout << ans << endl;
	return 0;
}