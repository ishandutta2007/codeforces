#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int n, m, k, cost[500][500][4], dp[500][500][11];
int dr[4] = {0, -1, 0, 1};
int dc[4] = {1, 0, -1, 0};

bool in(int r, int c) {
	return 0 <= r && r < n && 0 <= c && c < m;
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j + 1 < m; j++) {
			int x;
			cin >> x;
			cost[i][j][0] = cost[i][j + 1][2] = x;
		}

	for (int i = 0; i + 1 < n; i++)
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			cost[i][j][3] = cost[i + 1][j][1] = x;
		}


	for (int c = 1; c <= k / 2; c++) 
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
					dp[i][j][c] = 1e9;
					for (int d = 0; d < 4; d++) {
						int x = i + dr[d];
						int y = j + dc[d];
						if (!in(x, y))
							continue;
						dp[i][j][c] = min(dp[i][j][c], dp[x][y][c - 1] + cost[i][j][d]);
					}
				}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << (k % 2 ? -1 : 2 * dp[i][j][k / 2]) << " ";
		cout << endl;
	}

	return 0;
}