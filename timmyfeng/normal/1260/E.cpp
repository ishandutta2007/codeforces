#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 19;
const ll INF = 0x3f3f3f3f;

ll dp[(1 << MX) + 1][MX + 2];
int a[1 << MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int log = 31 - __builtin_clz(n);

	auto free = [&](int a) {
		return ((1 << a) - 1) << (log - a);
	};

	memset(dp, INF, sizeof dp);
	dp[n][0] = 0;
	int i = n - 1;
	for ( ; a[i] != -1; --i) {
		for (int j = 0; j <= log; ++j) {
			if (n - i <= free(j)) {
				dp[i][j] = min(dp[i][j], dp[i + 1][j]);
			}
			if (j) {
				dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + a[i]);
			}
		}
	}

	ll ans = (INF << 32) + INF;
	for (int j = 0; j <= log; ++j) {
		ans = min(ans, dp[i + 1][j]);
	}
	cout << ans << '\n';
}