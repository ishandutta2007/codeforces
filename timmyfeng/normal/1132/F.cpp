#include <bits/stdc++.h> 
using namespace std;

const int MX = 500;
int dp[MX][MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	for (int k = 1; k <= n; ++k) {
		for (int l = 0; l + k - 1 < n; ++l) {
			int r = l + k - 1;
			if (l == r) {
				dp[l][r] = 1;
			} else {
				dp[l][r] = k;
				for (int i = l; i < r; ++i) {
					dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r] - (s[l] == s[r]));
				}
			}
		}
	}
	cout << dp[0][n - 1] << '\n';
}