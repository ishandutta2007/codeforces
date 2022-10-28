#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> a(n + 2);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	a[n + 1] = m;

	vector<int> dp(n + 3);
	for (int i = n; i >= 0; --i) {
		dp[i] = a[i + 1] - a[i] + dp[i + 2];
	}

	int cur = 0, ans = dp[0];
	for (int i = 0; i < n; ++i) {
		if (i % 2) {
			cur += a[i] - a[i - 1];
			ans = max(ans, cur + a[i + 1] - a[i] - 1 + dp[i + 2]);
		} else {
			ans = max(ans, cur + a[i + 1] - a[i] - 1 + dp[i + 1]);
		}
	}
	cout << ans << '\n';
}