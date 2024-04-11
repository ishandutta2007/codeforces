#include <bits/stdc++.h> 
using namespace std;

const int MX = 2e5 + 1;
const int INF = 1e9;

int dp[MX][3][3], pre[MX][3][3];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();

		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j < 3; ++j) {
				for (int k = 0; k < 3; ++k) {
					dp[i][j][k] = INF;
					pre[i][j][k] = -1;
				}
			}
		}

		dp[0][0][0] = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 3; ++j) {
				for (int k = 0; k < 3; ++k) {
					if (dp[i][j][k] == INF)
						continue;

					int new_j = j + 1;
					if (s[i] != "one"[j]) {
						new_j = s[i] == 'o';
					}
					int new_k = k + 1;
					if (s[i] != "two"[k]) {
						new_k = s[i] == 't';
					}

					if (dp[i][j][k] + 1 < dp[i + 1][j][k]) {
						pre[i + 1][j][k] = j * 3 + k;
						dp[i + 1][j][k] = dp[i][j][k] + 1;
					}

					if (max(new_j, new_k) < 3 && dp[i][j][k] < dp[i + 1][new_j][new_k]) {
						pre[i + 1][new_j][new_k] = j * 3 + k;
						dp[i + 1][new_j][new_k] = dp[i][j][k];
					}
				}
			}
		}

		int i = n;
		int a = 0;
		int b = 0;
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				if (dp[i][j][k] < dp[i][a][b]) {
					a = j;
					b = k;
				}
			}
		}

		cout << dp[i][a][b] << "\n";
		while (i) {
			int new_a = pre[i][a][b] / 3;
			int new_b = pre[i][a][b] % 3;
			if (dp[i - 1][new_a][new_b] + 1 == dp[i][a][b]) {
				cout << i << " ";
			}
			--i;
			a = new_a;
			b = new_b;
		}
		cout << "\n";
	}
}