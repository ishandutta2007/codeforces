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
	int T;
	cin >> T;
	while (T--) {
		string s, t;
		cin >> s >> t;
		int n = SZ(s);
		vector<vector<int>> nxt(n, vector<int>(26));
		fill(all(nxt.back()), n);
		nxt[n - 1][s.back() - 'a'] = n - 1;
		for (int i = n - 2; i >= 0; i--) {
			nxt[i] = nxt[i + 1];
			nxt[i][s[i] - 'a'] = i;
		}
		int ptr = 0;
		bool ok = false;
		int ans = 1;
		for (int i = 0; i < SZ(t); i++) {
			if (ptr == n || nxt[ptr][t[i] - 'a'] == n) {
				ptr = 0;
				ans++;
			}
			if (nxt[ptr][t[i] - 'a'] == n) {
				ok = true;
				break;
			}
			ptr = nxt[ptr][t[i] - 'a'] + 1;
		}
		if (ok) {
			cout << -1 << '\n';
		}
		else {
			cout << ans << '\n';
		}
	}	
}