#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n, m; cin >> n >> m;
		string s[n+1];
		for(auto &i : s) {
			cin >> i;
			i.insert(begin(i), '0');
		}
		for(int i=n; --i>=0; )
			swap(s[i], s[i+1]);

		map<string, array<int, 2>> t2, t3;

		for(int i=1; i<=n; ++i) {
			for(int j=2; j<=m; ++j) {
				string oh;
				oh += s[i][j-1];
				oh += s[i][j];
				t2[oh] = {i, j-1};
			}
			for(int j=3; j<=m; ++j) {
				string oh;
				oh += s[i][j-2];
				oh += s[i][j-1];
				oh += s[i][j];
				t3[oh] = {i, j-2};
			}
		}
		int p[m+1], pos[m+1];
		int c[m+1];
		fill(p, p+m+1, -1);
		p[0] = 0;

		for(int i=2; i<=m; ++i) {
			string oh;
			oh += s[0][i-1];
			oh += s[0][i];

			if(p[i-2] >= 0 && t2[oh][0]) {
				c[i] = 2;
				p[i] = t2[oh][0];
				pos[i] = t2[oh][1];
			}

			if(i >= 3 && p[i] < 0 && p[i-3] >= 0) {
				oh = s[0][i-2] + oh;

				if(t3[oh][0]) {
					c[i] = 3;
					p[i] = t3[oh][0];
					pos[i] = t3[oh][1];
				}
			}

		}

		if(p[m] < 0) {
			cout << -1 << '\n';
		} else {
			deque<array<int, 3>> res;
			int u = m;
			while(u) {
				res.push_front({p[u], pos[u], pos[u]+c[u]-1});
				u -= c[u];
			}
			// res.pop_front();
			cout << size(res) << '\n';
			for(auto &[i, l, r] : res) {
				cout << l << ' ' << r << ' ' << i << '\n';
			}

		}
	}
}