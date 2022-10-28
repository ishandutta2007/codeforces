#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();
		vector<vector<int>> nxt(3, vector<int>(n + 1, -1));
		for (int i = n - 1; i >= 0; --i) {
			for (int j = 0; j < 3; ++j) {
				nxt[j][i] = nxt[j][i + 1];
			}
			nxt[s[i] - '1'][i] = i;
		}
		int ans = 1e9;
		for (int i = 0; i < n; ++i) {
			int mx = 0;
			bool ok = true;
			for (int j = 0; j < 3; ++j) {
				if (nxt[j][i] == -1) {
					ok = false;
				}
				mx = max(mx, nxt[j][i]);
			}
			if (ok) 
			ans = min(ans, mx - i + 1);
		}
		cout << (ans == 1e9 ? 0 : ans) << '\n';
	}
}