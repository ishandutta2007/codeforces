#include <bits/stdc++.h>
using namespace std;

const int M = (119 << 23) + 1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	while (t.size() < s.size()) {
		t += '?';
	}

	vector<vector<int>> dp(n, vector<int>(n));
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i + k < n; ++i) {
			int j = i + k;
			if (i == j) {
				if (t[i] == '?' || t[i] == s[k]) {
					dp[i][i] = 2;
				}
			} else {
				if (t[i] == '?' || t[i] == s[k]) {
					dp[i][j] = (dp[i][j] + dp[i + 1][j]) % M;
				}
				if (t[j] == '?' || t[j] == s[k]) {
					dp[i][j] = (dp[i][j] + dp[i][j - 1]) % M;
				}
			}
		}
	}
	
	int ans = 0;
	for (int i=  m - 1; i < n; ++i) {
		ans = (ans + dp[0][i]) % M;
	}
	cout << ans << '\n';
}