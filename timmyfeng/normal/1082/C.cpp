#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(m + 1);
	for (int i = 0; i < n; ++i) {
		int s, r;
		cin >> s >> r;
		a[s].push_back(r);
	}

	vector<int> nxt;
	for (int i = 1; i <= m; ++i) {
		sort(a[i].begin(), a[i].end(), greater<int>());
		for (int j = 1; j < (int)a[i].size(); ++j) {
			a[i][j] += a[i][j - 1];
		}
		if (!a[i].empty()) {
			nxt.push_back(i);
		}
	}

	int j = 0;
	int ans = 0;
	while (!nxt.empty()) {
		vector<int> cur;
		swap(cur, nxt);
		int res = 0;
		for (auto i : cur) {
			if (a[i][j] > 0) {
				res += a[i][j];
			}
			if ((int)a[i].size() > j + 1) {
				nxt.push_back(i);
			}
		}
		ans = max(ans, res);
		++j;
	}
	cout << ans << '\n';
}