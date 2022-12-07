#include <bits/stdc++.h>

using namespace std;

int t, n, a[1 << 20], dp[1 << 20];

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		int ans = 0;
		memset(dp, 0, sizeof dp);
		for (int i = n - 1; 0 <= i; i--) {
			int x = a[i];
			if (!dp[x])
				for (int e = 2 * x; e <= 200000; e += x)
					dp[x] = max(dp[x], dp[e]);
			ans = max(ans, ++dp[x]);
		}
		cout << n - ans << "\n";
	}
	return 0;
}