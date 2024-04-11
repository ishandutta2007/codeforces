#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	
	int ans = n;
	int cnt = count(s.begin(), s.end(), '1');
	for (int i = 0; i < k; ++i) {
		string cur = "";
		for (int j = i; j < n; j += k) {
			cur += s[j];
		}

		int m = cur.size();
		vector<int> ps(m + 1);
		for (int j = 1; j <= m; ++j) {
			ps[j] = ps[j - 1];
			if (cur[j - 1] == '1') {
				--ps[j];
			} else {
				++ps[j];
			}
		}

		int res = 0;
		int mn = 1e9;
		for (int j = m; j; --j) {
			mn = min(mn, ps[j]);
			res = min(res, mn - ps[j - 1]);
		}
		ans = min(ans, res + cnt);
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