#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

bool check(int a, int b, int ff, vector<vector<bool>> &used) {
	for (int i = 0; i <= ff; i++) {
		if (used[a + ff][b + i]) {
			return false;
		}
		if (used[a + i][b + ff]) {
			return false;
		}
	}
	return true;
}

int get_min(int a, int b, vector<vector<vector<bool>>> &can) {
	for (int i = 0; i < 26; i++) {
		if (can[a][b][i]) {
			return i;
		}
	}
	return 26;
}

signed main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<vector<vector<bool>>> can(n, vector<vector<bool>>(m, vector<bool>(26, true)));
	vector<vector<bool>> used(n, vector<bool>(m, false));
	vector<vector<char>> ans(n, vector<char>(m));
	vector<pair<int, int>> delta = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (used[i][j]) {
				continue;
			}
			int cur = 0;
			while (!can[i][j][cur]) {
				cur++;
			}
			int ff = 1;
			while (i + ff < n && j + ff < m && check(i, j, ff, used) && get_min(i, j + ff, can) == cur) {
				ff++;
			}
			for (int i2 = i; i2 < i + ff; i2++) {
				for (int j2 = j; j2 < j + ff; j2++) {
					used[i2][j2] = true;
					fill(all(can[i2][j2]), false);
					for (auto it : delta) {
						int i3 = i2 + it.F, j3 = j2 + it.S;
						if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) {
							can[i3][j3][cur] = false;
						}
					}
					ans[i2][j2] = char('A' + cur);
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j];
		}
		cout << '\n';
	}
}