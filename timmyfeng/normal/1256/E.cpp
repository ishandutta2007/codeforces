#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	int n;
	cin >> n;
	vector<pair<int, int>> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin() + 1, a.end());

	vector<int> dp(n - 2);
	for (int i = 3; i <= n - 3; ++i) {
		dp[i] = max(dp[i - 1], dp[i - 3] + a[i + 1].first - a[i].first);
	}

	int cur = 1;
	vector<int> ans(n + 1);
	for (int i = 0; i < 3; ++i) {
		ans[a[n - i].second] = 1;
	}
	int j = n - 3;
	while (j) {
		if (dp[j] == dp[j - 1]) {
			ans[a[j--].second] = cur;
		} else {
			++cur;
			int k = j - 3;
			for ( ; j > k; --j) {
				ans[a[j].second] = cur;
			}
		}
	}
	
	cout << a[n].first - a[1].first - dp[n - 3] << ' ' << cur << '\n';
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}