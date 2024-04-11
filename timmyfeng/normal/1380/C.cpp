#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;

		vector<int> a(n);
		for (auto& i : a) {
			cin >> i;
		}
		sort(a.begin(), a.end());

		vector<int> dp(n + 1);
		for (int i = 0; i < n; ++i) {
			int required = (x - 1) / a[i] + 1;
			if (i + required <= n) {
				dp[i + required] = max(dp[i + required], dp[i] + 1);
			}
			dp[i + 1] = max(dp[i + 1], dp[i]);
		}
		cout << dp[n] << "\n";
	}
}