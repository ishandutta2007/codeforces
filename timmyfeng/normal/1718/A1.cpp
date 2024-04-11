#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;

	while (t--) {
		int n; cin >> n;

		vector<int> a(n);
		for (auto &i : a) cin >> i;

		int sum = 0;
		vector<int> dp(n + 1);
		map<int, int> prev = {{0, 0}};
		for (int i = 0; i < n; ++i) {
			sum ^= a[i];
			dp[i + 1] = dp[i] + 1;
			if (prev.count(sum)) {
				dp[i + 1] = min(dp[i + 1], dp[prev[sum]] + i - prev[sum]);
			}
			prev[sum] = i + 1;
		}

		cout << dp[n] << "\n";
	}
}