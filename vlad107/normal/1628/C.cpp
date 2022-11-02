#include <iostream>
#include <vector>

using namespace std;

void add(vector<vector<int>> &cnt, int x, int y) {
	if (x > 0) {
		++cnt[x - 1][y];
	}
	if (y > 0) {
		++cnt[x][y - 1];
	}
	if (x + 1 < cnt.size()) {
		++cnt[x + 1][y];
	}
	if (y + 1 < cnt[x].size()) {
		++cnt[x][y + 1];
	}
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<vector<int>> a(n, vector<int>(n, 0));
		for (auto &row : a) {
			for (int &x : row) cin >> x;
		}
		vector<vector<int>> cnt(n, vector<int>(n, 0));
		add(cnt, 0, 0);
		int res = a[0][0];
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ((cnt[i - 1][j] % 2) == 0) {
					add(cnt, i, j);
					res ^= a[i][j];
				}
			}
		}
		// for (int i = 0; i < n; i++) {
		// 	for (int j = 0; j < n; j++) {
		// 		assert(cnt[i][j] % 2 == 1);
		// 	}
		// }
		cout << res << "\n";
	}
	return 0;
}