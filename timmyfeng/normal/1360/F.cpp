#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<string> s(n);
		for (auto& i : s) {
			cin >> i;
		}

		string ans = "-1";
		bool ok = false;
		for (int i = 0; i < m && !ok; ++i) {
			for (int j = 0; j < n && !ok; ++j) {
				string mat = s[0];
				mat[i] = s[j][i];
				ok = true;
				for (int k = 0; k < n; ++k) {
					int cnt = 0;
					for (int l = 0; l < m; ++l) {
						cnt += (mat[l] != s[k][l]);
					}
					if (cnt > 1) {
						ok = false;
						break;
					}
				}
				if (ok) {
					ans = mat;
				}
			}
		}
		cout << ans << '\n';
	}
}