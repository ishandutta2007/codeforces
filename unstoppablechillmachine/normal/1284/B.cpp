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
	int n;
	cin >> n;
	vector<vector<int>> a(n);
	vector<int> kek, mn(n), mx(n);
	vector<bool> ok(n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int len;
		cin >> len;
		a[i].resize(len);
		for (auto &it : a[i]) {
			cin >> it;
		}
		for (int j = 0; j + 1 < len; j++) {
			if (a[i][j] < a[i][j + 1]) {
				ok[i] = true;
			}
		}
		mn[i] = mx[i] = a[i][0];
		for (int j = 1; j < len; j++) {
			mn[i] = min(mn[i], a[i][j]);
			mx[i] = max(mx[i], a[i][j]);
		}
		//cout << mn[i] << ' ' << mx[i] << '\n';
		if (!ok[i]) {
			kek.pb(mx[i]);
		}
		else {
			cnt++;
		}
	}
	sort(all(kek));
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (ok[i]) {
			ans += n;
		}
		else {
			ans += cnt;
			ans += kek.end() - upper_bound(all(kek), mn[i]);
		}
		//cout << ans << '\n';
	}
	cout << ans << '\n';
}