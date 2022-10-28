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

		vector<vector<int>> grid(n, vector<int>(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> grid[i][j];
			}
		}

		int row = 0;
		int col = 0;
		for (int i = 0; i < n; ++i) {
			row += !count(grid[i].begin(), grid[i].end(), 1);
		}
		for (int i = 0; i < m; ++i) {
			int cnt = 0;
			for (int j = 0; j < n; ++j) {
				cnt += grid[j][i];
			}
			col += !cnt;
		}

		cout << (min(row, col) % 2 ? "Ashish" : "Vivek") << '\n';
	}
}