#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 3e5;

ll dp[MX + 1][3], a[MX + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		dp[i][0] = max(0LL, dp[i - 1][0]) + a[i];
		dp[i][1] = max({0LL, dp[i - 1][1], dp[i - 1][0]}) + a[i] * x;
		dp[i][2] = max({0LL, dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + a[i];
		ans = max({ans, dp[i][0], dp[i][1], dp[i][2]});
	}
	cout << ans << '\n';
}