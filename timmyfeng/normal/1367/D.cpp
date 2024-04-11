#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string s;
		int m;
		cin >> s >> m;
		vector<int> b(m);
		for (auto& i : b) {
			cin >> i;
		}

		vector<int> cnt(26);
		for (auto i : s) {
			++cnt[i - 'a'];
		}

		vector<int> pos;
		int cur = 25;
		string ans(m, 0);
		while (count(ans.begin(), ans.end(), 0)) {
			vector<int> todo;
			for (int i = 0; i < m; ++i) {
				if (!ans[i]) {
					int res = 0;
					for (auto j : pos) {
						res += abs(j - i);
					}
					if (res == b[i]) {
						todo.push_back(i);
					}
				}
			}
			while (cnt[cur] < int(todo.size())) {
				--cur;
			}
			for (auto i : todo) {
				ans[i] = cur + 'a';
				pos.push_back(i);
			}
			--cur;
		}

		cout << ans << "\n";
	}
}