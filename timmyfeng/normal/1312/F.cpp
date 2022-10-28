#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int BASE = 50;
const int MX = 3e5;

int grun[BASE * 2][3], per;
ll a[MX + 1];

int mex(const vector<int>& sta) {
	for (int i = 0; i < (int)sta.size(); ++i) {
		if (!count(sta.begin(), sta.end(), i))
			return i;
	}
	return sta.size();
}

int get(ll n, int t) {
	if (n < 50)
		return grun[n][t];
	return grun[((n - 50) % per) + 50][t];
}

void solve() {
	int n, x, y, z;
	cin >> n >> x >> y >> z;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 1; ; ++i) {
		int t = i - x > 0 ? i - x : 0;
		int u = i - y > 0 ? i - y : 0;
		int v = i - z > 0 ? i - z : 0;
		grun[i][0] = mex({grun[t][0], grun[u][1], grun[v][2]});
		grun[i][1] = mex({grun[t][0], grun[v][2]});
		grun[i][2] = mex({grun[t][0], grun[u][1]});
		if (i > BASE + 4) {
			bool ok = true;
			for (int k = 0; k < 5; ++k) {
				for (int j = 0; j < 3; ++j) {
					ok &= (grun[k + BASE][j] == grun[i - 4 + k][j]);
				}
			}
			if (ok) {
				per = i - 4 - BASE;
				break;
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum ^= get(a[i], 0);
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int tgt = sum ^ get(a[i], 0);
		ll t = a[i] - x > 0 ? a[i] - x : 0;
		ll u = a[i] - y > 0 ? a[i] - y : 0;
		ll v = a[i] - z > 0 ? a[i] - z : 0;
		ans += (get(t, 0) == tgt);
		ans += (get(u, 1) == tgt);
		ans += (get(v, 2) == tgt);
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}