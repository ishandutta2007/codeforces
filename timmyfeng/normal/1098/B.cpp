#include <bits/stdc++.h>
using namespace std;

pair<vector<string>, int> calc(vector<string> grid, int a, int b) {
	int n = grid.size();
	int m = grid[0].size();

	int c = 0;
	while (c == a || c == b) {
		++c;
	}
	int d = c + 1;
	while (d == a || d == b) {
		++d;
	}

	int cnt = 0;
	vector<string> ans(n, string(m, 0));
	for (int i = 0; i < n; ++i) {
		int e = (i % 2 == 0 ? a : c);
		int f = (i % 2 == 0 ? b : d);
		vector<int> phase(2);

		for (int j = 0; j < m; ++j) {
			phase[j % 2] += (grid[i][j] != "AGCT"[e]);
			phase[(j % 2) ^ 1] += (grid[i][j] != "AGCT"[f]);
		}

		for (int j = 0; j < m; ++j) {
			if ((j % 2 == 1) ^ (phase[0] < phase[1])) {
				ans[i][j] = "AGCT"[e];
			} else {
				ans[i][j] = "AGCT"[f];
			}
		}

		cnt += min(phase[0], phase[1]);
	}
	return make_pair(ans, cnt);
}

pair<vector<string>, int> solve(vector<string> grid) {
	pair<vector<string>, int> res;
	res.second = 1e9;
	for (int a = 0; a < 4; ++a) {
		for (int b = a + 1; b < 4; ++b) {
			auto cur = calc(grid, a, b);	
			if (cur.second < res.second) {
				swap(res, cur);
			}
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<string> grid(n);
	for (int i = 0; i < n; ++i) {
		cin >> grid[i];
	}

	auto ans1 = solve(grid);

	vector<string> trans(m, string(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			trans[j][i] = grid[i][j];
		}
	}

	auto ans2 = solve(trans);

	if (ans1.second < ans2.second) {
		for (auto& i : ans1.first) {
			cout << i << "\n";
		}
	} else {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << ans2.first[j][i];
			}
			cout << "\n";
		}
	}
}