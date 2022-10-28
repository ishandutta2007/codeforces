#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	string s;
	cin >> n >> k >> s;

	vector<pair<int, int>> ans;
	queue<pair<int, int>> q;
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == 'R' && s[i + 1] == 'L') {
			q.emplace(i, 0);
		}
	}
	int ct = 0;
	while (!q.empty()) {
		auto[u, d] = q.front();
		if (!ans.empty() && d == ans.back().second) {
			++ct;
		}
		ans.emplace_back(q.front());
		q.pop();
		s[u] = 'L';
		s[u + 1] = 'R';
		if (u && s[u - 1] == 'R') {
			q.emplace(u - 1, d + 1);
		}
		if (u + 2 < n && s[u + 2] == 'L') {
			q.emplace(u + 1, d + 1);
		}
	}

	if (ans.size() < k || ans.size() - ct > k) {
		cout << -1 << '\n';
	} else {
		int offset = ans.size() - k;
		for (int i = 0; i < ans.size(); ) {
			int j = i;
			for ( ; offset && ans[j + 1].second == ans[i].second; ++j, --offset);
			cout << j - i + 1 << ' ';
			for ( ; i <= j; ++i) {
				cout << ans[i].first + 1 << ' ';
			}
			cout << '\n';
		}
	}
}