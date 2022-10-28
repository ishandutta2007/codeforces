#include <bits/stdc++.h>
using namespace std;

int dp[100001], x[80], s[80];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> s[i];
	}
	
	for (int i = m - 1; ~i; --i) {
		dp[i] = m - i;
		for (int j = 0; j < n; ++j) {
			int l = x[j] - s[j];
			int r = x[j] + s[j];
			if (l <= i + 1 && r >= i + 1) {
				dp[i] = dp[i + 1];
			}
			if (l > i) {
				int cost = l - (i + 1);
				dp[i] = min(dp[i], cost + dp[min(m, r + cost)]);
			}
		}
	}
	cout << dp[0] << '\n';
}