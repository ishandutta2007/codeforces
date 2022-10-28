#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	vector<vector<int>> pos(26);
	for (int i = 0; i < n; ++i) {
		pos[s[i] - 'a'].push_back(i + 1);
	}

	int m;
	cin >> m;
	while (m--) {
		string t;
		cin >> t;
		int ans = 0;
		for (int i = 0; i < 26; ++i) {
			int cnt = count(t.begin(), t.end(), i + 'a');
			if (cnt) {
				ans = max(ans, pos[i][cnt - 1]);
			}
		}
		cout << ans << '\n';
	}
}