#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e5;
const int AL = 6;

int cnt_let[1 << AL], cnt_mat[1 << AL], pos[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int n = s.size();
	for (auto c : s) {
		for (int mask = 0; mask < (1 << AL); ++mask) {
			cnt_let[mask] += !!(mask & (1 << (c - 'a')));
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int a;
		string t;
		cin >> a >> t;
		for (auto c : t) {
			pos[a - 1] ^= 1 << (c - 'a');
		}
	}

	for (int i = 0; i < n; ++i) {
		if (!pos[i]) {
			pos[i] = (1 << AL) - 1;
		}
		for (int mask = 0; mask < (1 << AL); ++mask) {
			cnt_mat[mask] += !!(mask & pos[i]);
		}
	}

	string ans(n, 0);
	for (int i = 0; i < n; ++i) {
		for (int mask = 0; mask < (1 << AL); ++mask) {
			cnt_mat[mask] -= !!(mask & pos[i]);
		}

		int res = 0;
		for ( ; res < AL; ++res) {
			if (!(pos[i] & (1 << res)))
				continue;
			bool ok = true;
			for (int mask = 0; mask < (1 << AL) && ok; ++mask) {
				int cnt = cnt_let[mask] - !!(mask & (1 << res));
				ok &= (cnt <= cnt_mat[mask]);
			}
			if (ok)
				break;
		}

		if (res == AL) {
			cout << "Impossible" << '\n';
			return 0;
		}

		for (int mask = 0; mask < (1 << AL); ++mask) {
			cnt_let[mask] -= !!(mask & (1 << res));
		}
		ans[i] = res + 'a';
	}
	cout << ans << '\n';
}