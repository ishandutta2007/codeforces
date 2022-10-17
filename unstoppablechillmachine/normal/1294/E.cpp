#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define int ll

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> x(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> x[i][j];
		}
	}
	int ans = 0;
	vector<int> cnt(n);
	for (int j = 1; j <= m; j++) {
		fill(all(cnt), n);
		for (int i = 1; i <= n; i++) {
			int ost = x[i][j] % m;
			if (ost == 0) {
				ost = m;
			}
			if (ost != j || x[i][j] > n * m) {
				continue;
			}
			int sd = i - ((x[i][j] - 1) / m + 1);
			if (sd < 0) {
				sd += n;
			}
			cnt[sd]--;
		}
		int best = cnt[0];
		for (int i = 1; i < n; i++) {
			best = min(best, cnt[i] + i);
		}
		//cout << best << '\n';
		ans += best;
	}
	cout << ans << '\n';
}