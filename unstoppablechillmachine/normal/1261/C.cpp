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

vector<vector<int>> pref;

inline int get_sum(int a, int b, int a2, int b2) {
	return pref[a2][b2] - pref[a - 1][b2] - pref[a2][b - 1] + pref[a - 1][b - 1];
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	pref = vector<vector<int>>(n + 1, vector<int>(m + 1));
	vector<vector<char>> c(n + 1, vector<char>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c[i][j];
			if (c[i][j] == 'X') {
				pref[i][j] = 1;
			}
			pref[i][j] += pref[i][j - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			pref[i][j] += pref[i - 1][j];
		}
	}
	int l = 0, r = min(n, m) / 2 + 2;
	vector<vector<int>> dp(n + 2, vector<int>(m + 2));
	while (r - l > 1) {
		int mid = (l + r) / 2, sz = (2 * mid + 1) * (2 * mid + 1);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = 0;
			}
		}
		for (int i = mid + 1; i + mid <= n; i++) {
			for (int j = mid + 1; j + mid <= m; j++) {
				if (get_sum(i - mid, j - mid, i + mid, j + mid) == sz) {
					dp[i + mid][j + mid]++;
					dp[i + mid][j - mid - 1]--;
					dp[i - mid - 1][j + mid]--;
					dp[i - mid - 1][j - mid - 1]++;
				}
			}
		}
		bool ok = true;
		for (int i = n; i >= 1; i--) {
			for (int j = m; j >= 1; j--) {
				dp[i][j] += dp[i + 1][j] + dp[i][j + 1] - dp[i + 1][j + 1];
				if (!dp[i][j] && c[i][j] == 'X') {
					ok = false;
					break;
				}
			}
		}
		if (ok) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	cout << l << '\n';
	int sz = (2 * l + 1) * (2 * l + 1), mid = l;
	vector<vector<char>> ans(n + 1, vector<char>(m + 1, '.'));
	for (int i = mid + 1; i + mid <= n; i++) {
		for (int j = mid + 1; j + mid <= m; j++) {
			if (get_sum(i - mid, j - mid, i + mid, j + mid) == sz) {
				ans[i][j] = 'X';
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << ans[i][j];
		}
		cout << '\n';
	}	
}