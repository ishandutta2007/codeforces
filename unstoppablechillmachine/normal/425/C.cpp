#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

const int INF = 1e9 + 10;
const int N = 1e5 + 10;
const int MX = 310;
int dp[N][MX], a[N], b[N];
vector<int> arr[N];
signed main() {
	int n, m, s, e;
	cin >> n >> m >> s >> e;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}	
	for (int j = 1; j <= m; j++) {
		cin >> b[j];
		arr[b[j]].pb(j);
	}
	int MX = s / e;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= MX; j++) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= MX; j++) {
			if (dp[i][j] == INF) {
				continue;
			}
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			int ps = upper_bound(all(arr[a[i + 1]]), dp[i][j]) - arr[a[i + 1]].begin(), vl;
			if (ps == SZ(arr[a[i + 1]])) {
				vl = INF;
			}
			else {
				vl = arr[a[i + 1]][ps];
			}
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], vl);
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= MX; j++) {
			if (dp[i][j] < INF) {
				if (e * j + i + dp[i][j] <= s) {
					ans = max(ans, j);
				}
			}
		}
	}
	cout << ans << '\n';
}