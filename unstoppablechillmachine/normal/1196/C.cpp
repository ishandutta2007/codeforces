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

signed main() {
  ios_base::sync_with_stdio(0);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<int> x(n), y(n);
		vector<vector<int>> f(4, vector<int>(n));
		int mxx = -1e5, mnx = 1e5, mxy = -1e5, mny = 1e5;
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i];
			for (int j = 0; j < 4; j++) {
				cin >> f[j][i];
			}
			if (f[0][i] == 0) {
				mxx = max(mxx, x[i]);
			}
			if (f[2][i] == 0) {
				mnx = min(mnx, x[i]);
			}
			if (f[3][i] == 0) {
				mxy = max(mxy, y[i]);
			}
			if (f[1][i] == 0) {
				mny = min(mny, y[i]);
			}
		}
		pair<int, int> ans = {INF, INF};
		if (mnx >= mxx && mny >= mxy) {
			ans = {mnx, mny};
		}
		if (ans.F == INF) {
			cout << 0 << '\n';
		}
		else {
			cout << 1 << ' ' << ans.F << ' ' << ans.S << '\n';
		}
	} 
}