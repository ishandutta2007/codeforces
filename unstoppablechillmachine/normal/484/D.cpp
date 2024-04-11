#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

signed main() {
	int n;
	cin >> n;
	vector<int> a(n + 1), dp(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int cur = 0, mx;
	for (int i = 2; i <= n; i++) {
		if (a[i] == a[i - 1]) {
			cur = 0;
			dp[i] = dp[i - 1];
		}
		if (a[i] > a[i - 1]) {
			if (cur == 1) {
				mx = max(mx, dp[i - 1] - a[i]);
			}
			else {
				cur = 1;
				mx = max(dp[i - 1] - a[i], dp[i - 2] - a[i - 1]);
			}
			dp[i] = mx + a[i];
		}
		if (a[i] < a[i - 1]) {
			if (cur == 2) {
				mx = max(mx, dp[i - 1] + a[i]);
			}
			else {
				cur = 2;
				mx = max(dp[i - 1] + a[i], dp[i - 2] + a[i - 1]);
			}
			dp[i] = mx - a[i];
		}
	}	
	cout << dp[n] << '\n';
	cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}