#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1000000000));
		dp[0][0] = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			for (int j = 0; j <= i; j++) {
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + (i + 1 - j == x));
			}
		}
		int res = n;
		for (int i = 0; i <= n; i++)
			if (dp[n][i] >= k)
				res = min(res, i);	
		cout << (res == n ? -1 : res) << "\n";
	}
	return 0;
}