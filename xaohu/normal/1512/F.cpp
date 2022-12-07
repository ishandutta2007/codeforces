#include <bits/stdc++.h>

using namespace std;

const int N = 321123;

int t, n, c, a[N], b[N];
pair<long long, int> dp[N];

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> c;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i + 1 < n; i++)
			cin >> b[i];
		long long ans = 1e18;
		auto f = [&](int s, int e, int add) {
			return max(0, (e - s + add - 1) / add);
		};
		for (int i = 0; i < n; i++) {
			ans = min(ans, dp[i].first + f(dp[i].second, c, a[i]));
			if (i + 1 < n) {
				int cnt = f(dp[i].second, b[i], a[i]);
				int have = dp[i].second + a[i] * cnt;
				dp[i + 1] = {dp[i].first + cnt + 1, have - b[i]};
			}	
		}
		cout << ans << "\n";
	}
	return 0;
}