#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;

	while (t--) {
		int n, m; cin >> n >> m;
		string s; cin >> s;

		for (int i = 0; i < min(n, m); ++i) {
			string s_new = s;
			for (int j = 0; j < n; ++j) {
				if ((j && s[j - 1] == '1') ^ (j + 1 < n && s[j + 1] == '1')) {
					s_new[j] = '1';
				}
			}
			swap(s, s_new);
		}

		cout << s << "\n";
	}
}