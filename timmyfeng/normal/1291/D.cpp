#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int q;
	cin >> s >> q;

	vector<vector<int>> ps(s.size() + 1, vector<int>(26));
	for (int i = 1; i <= s.size(); i++) {
		for (int j = 0; j < 26; j++) {
			ps[i][j] = ps[i - 1][j];
		}
		++ps[i][s[i - 1] - 'a'];
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		bool ok = (l == r || s[l - 1] != s[r - 1]);
		if (!ok) {
			int ct = 0;
			for (int i = 0; i < 26; i++) {
				if (ps[r][i] - ps[l - 1][i]) {
					++ct;
				}
			}
			if (ct > 2) {
				ok = true;
			}
		}
		cout << (ok ? "Yes\n" : "No\n");
	}
}