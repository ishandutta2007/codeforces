#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
//#define int ll

const int N = 3510;
int dp[N][N], a[N], take[N];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, m, k;
		cin >> n >> m >> k;
		int len = n - m + 1;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i + len - 1 <= n; i++) {
			take[i] = max(a[i], a[i + len - 1]);
		}
		for (int l = 1; l + len - 1 <= n; l++) {
			dp[l][l] = take[l];
			for (int r = l + 1; r + len - 1 <= n; r++) {
				dp[l][r] = min(take[r], dp[l][r - 1]);
			}
		}
		k = min(k, m - 1);
		int ans = 0;
		for (int f = 0; f <= k; f++) {
			for (int s = 0; f + s <= k; s++) {
				int from = 1 + f, to = 1 + f + (m - 1 - f - s);
				ans = max(ans, dp[from][to]);
			}
		}
		cout << ans << '\n';
	}
}