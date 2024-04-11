#include <bits/stdc++.h>
using namespace std;

vector<string> col, dir;
vector<vector<int>> comp, dp, tin;
vector<int> len;
int t, cur;

void trav(int r, int c) {
	tin[r][c] = ++t;
	int nr = r, nc = c;
	if (dir[r][c] == 'U') {
		--nr;
	} else if (dir[r][c] == 'D') {
		++nr;
	} else if (dir[r][c] == 'R') {
		++nc;
	} else {
		--nc;
	}
	if (tin[nr][nc]) {
		len.push_back(++t - tin[nr][nc]);
		comp[r][c] = cur++;
		dp[r][c] = 0;
	} else {
		if (dp[nr][nc] == -1) {
			trav(nr, nc);
		}
		comp[r][c] = comp[nr][nc];
		dp[r][c] = (dp[nr][nc] + 1) % len[comp[r][c]];
	}
	tin[r][c] = 0;
}

void solve() {
	int n, m;
	cin >> n >> m;
	col.resize(n);
	dir.resize(n);
	for (auto& i : col) {
		cin >> i;
	}
	for (auto& i : dir) {
		cin >> i;
	}

	comp.assign(n, vector<int>(m, -1));
	dp.assign(n, vector<int>(m, -1));
	tin.assign(n, vector<int>(m));
	len.clear();
	t = cur = 0;
	
	set<pair<int, int>> ans2;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (dp[i][j] == -1) {
				trav(i, j);
			}
			if (col[i][j] == '0') 
			ans2.emplace(comp[i][j], dp[i][j]);
		}
	}
	int ans1 = 0;
	for (auto i : len) {
		ans1 += i;
	}
	cout << ans1 << ' ' << ans2.size() << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}