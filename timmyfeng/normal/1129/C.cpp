#include <bits/stdc++.h>
using namespace std;

const int N = 3001;
const int M = 1e9 + 7;

int pi[N][N];
int dp[N];

int add(int a, int b) {
	return (a += b) < M ? a : a - M;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m;
	cin >> m;

	string s;
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		char c;
		cin >> c;
		s += c;

		memset(dp, 0, sizeof dp);
		dp[i + 1] = 1;
		for (int j = i + 1; j; --j) {
			for (int len = 1; len <= 4 && len <= j; ++len) {
				if (len == 4) {
					string t = s.substr(j - len, len);
					if (t == "0011" || t == "0101" || t == "1110" || t == "1111") {
						continue;
					}
				}

				dp[j - len] = add(dp[j - len], dp[j]);
			}
		}

		int len = 0;
		for (int j = 0; j < i; ++j) {
			// s[j..i]
			int link = pi[j][i - j - 1];
			while (link && s[i] != s[link + j]) {
				link = pi[j][link - 1];
			}
			if (s[i] == s[link + j]) {
				++link;
			}
			pi[j][i - j] = link;
			len = max(len, link);
			//cout << j << " " << link << "\n";
		}

		//cout << len + 1 << "\n";
		for ( ; len <= i; ++len) {
			ans = add(ans, dp[i - len]);
		}
		cout << ans << "\n";
	}
}