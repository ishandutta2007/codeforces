#include <bits/stdc++.h> 
using namespace std;

long long dp[1000000 + 1][3];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int n = s.size();

	dp[0][0] = 1;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'o') {
			dp[i + 1][2] += dp[i][1];
		} else if (i + 1 < n && s[i] == 'v' && s[i + 1] == 'v') {
			dp[i + 2][1] += dp[i][0];
			ans += dp[i][2];
		}
		for (int j = 0; j < 3; ++j) {
			dp[i + 1][j] += dp[i][j];
		}
	}
	cout << ans << "\n";
}