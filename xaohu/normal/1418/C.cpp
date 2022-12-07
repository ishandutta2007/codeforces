#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)

typedef long long ll;
using namespace std;

int dp[200005][2];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector <int> a(n, 0);
		for (auto &x : a) cin >> x;
		a.push_back(0); 
		a.push_back(0);
		FOR(i, n + 2) dp[i][0] = dp[i][1] = 1e9;
		dp[0][1] = a[0];
		dp[1][1] = a[0] + a[1];
		FOR(i, n)
			FOR(j, 2) {
				int c1 = a[i + 1], c2 = a[i + 2];
				if (j == 1) c1 = c2 = 0;
				dp[i + 1][!j] = min(dp[i + 1][!j], dp[i][j] + c1);
				dp[i + 2][!j] = min(dp[i + 2][!j], dp[i][j] + c1 + c2);
			}
		cout << min(dp[n][0], dp[n][1]) << endl;
	}
		
	return 0;
}