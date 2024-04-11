#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 5e5;

int a[MX], b[MX], p[MX];
vector<int> pos[MX + 1];
ll dp[MX], ft[MX];
int n;

void upd(int a, int val) {
	for ( ; a < n; a |= a + 1) {
		ft[a] += val;
	}
}

ll query(int a) {
	ll res = 0;
	for ( ; a >= 0; a &= a + 1, --a) {
		res += ft[a];
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		pos[a[i]].push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	
	fill(dp, dp + n, -1e18);
	for (auto i : pos[b[0]]) {
		dp[i] = p[i];
	}
	for (int i = 1; i <= b[0]; ++i) {
		for (auto j : pos[i]) {
			if (p[j] > 0) {
				upd(j, p[j]);
			}
		}
	}

	for (int i = 1; i < m; ++i) {
		vector<int> pt;
		for (auto j : pos[b[i - 1]]) {
			pt.push_back(j);
		}
		for (auto j : pos[b[i]]) {
			pt.push_back(j);
		}
		sort(pt.begin(), pt.end());

		ll mx = -1e18, prev = -1;
		for (auto j : pt) {
			mx += query(j) - query(prev);
			if (a[j] == b[i - 1]) {
				mx = max(mx, dp[j]);
			} else {
				dp[j] = mx + p[j];
			}
			prev = j;
		}

		for (int j = b[i - 1] + 1; j <= b[i]; ++j) {
			for (auto k : pos[j]) {
				if (p[k] > 0) { 
					upd(k, p[k]);
				}
			}
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += p[i];
	}
	ll mx = -1e18;
	for (auto i : pos[b[m - 1]]) {
		mx = max(mx, dp[i] + query(n - 1) - query(i));
	}
	ans -= mx;
	if (ans > 1e17) {
		cout << "NO" << '\n';
	} else {
		cout << "YES" << '\n';
		cout << ans << '\n';
	}
}