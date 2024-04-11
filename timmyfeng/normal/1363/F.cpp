#include <bits/stdc++.h> 
using namespace std;

const int MX = 2000 + 1;
const int AL = 26;

int pre_sum[AL][MX][2], dp[MX][MX];

bool anagram(string s, string t) {
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	return s == t;
}

void solve() {
	int n;
	string s, t;
	cin >> n >> s >> t;

	if (!anagram(s, t)) {
		cout << -1 << '\n';
		return;
	}

	for (int i = 0; i < 26; ++i) {
		for (int j = 1; j <= n; ++j) {
			pre_sum[i][j][0] = pre_sum[i][j - 1][0] + (s[j - 1] == 'a' + i);
			pre_sum[i][j][1] = pre_sum[i][j - 1][1] + (t[j - 1] == 'a' + i);
		}
	}

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			dp[i][j] = j ? 1e9 : 0;
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			int c = t[i - 1] - 'a';
			if (pre_sum[c][j][0] < pre_sum[c][i][1]) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			}
			if (t[i - 1] == s[j - 1]) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
			}
			dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
		}
	}
	cout << dp[n][n] << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}