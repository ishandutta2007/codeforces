#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for (auto& i : grid) {
		cin >> i;
	}

	int mnr = 1e9, mnc = 1e9;
	vector<int> bestr, bestc;
	for (int i = 0; i < n; ++i) {
		int cnt = count(grid[i].begin(), grid[i].end(), '.');
		if (cnt == mnr) {
			bestr.push_back(i);
		} else if (cnt < mnr) {
			mnr = cnt;
			bestr = {i};
		}
	}
	for (int i = 0; i < m; ++i) {
		int cnt = 0;
		for (auto j = 0; j < n; ++j) {
			cnt += (grid[j][i] == '.');
		}
		if (cnt == mnc) {
			bestc.push_back(i);
		} else if (cnt < mnc) {
			mnc = cnt;
			bestc = {i};
		}
	}
	
	bool ok = false;
	for (auto i : bestr) {
		for (auto j : bestc) {
			if (grid[i][j] == '.') {
				ok = true;
			}
		}
	}

	cout << mnr + mnc - ok << '\n';
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