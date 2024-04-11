#include<vector>
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100, K = 11;
int n, m, k, dp[N][N][K], a[N][N];
char fa[N][N][K];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i) {
		char buf[105];
		scanf("%s", buf);
		for (int j = 0; j < m; ++j) {
			a[i][j] = buf[j] - '0';
		}
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < m; ++i) {
		dp[n - 1][i][a[n - 1][i] % (k + 1)] = a[n - 1][i];
	}
	for (int i = n - 1; i > 0; --i) {
		for (int j = 0; j < m; ++j) {
			for (int l = 0; l < k + 1; ++l) {
				if (dp[i][j][l] == -1) {
					continue;
				}
				if (j) {
					int &target = dp[i - 1][j - 1][(l + a[i - 1][j - 1]) % (k + 1)];
					if (target < dp[i][j][l] + a[i - 1][j - 1]) {
						target = dp[i][j][l] + a[i - 1][j - 1];
						fa[i - 1][j - 1][(l + a[i - 1][j - 1]) % (k + 1)] = 'L';
					}
				}
				if (j != m - 1) {
					int &target = dp[i - 1][j + 1][(l + a[i - 1][j + 1]) % (k + 1)];
					if (target < dp[i][j][l] + a[i - 1][j + 1]) {
						target = dp[i][j][l] + a[i - 1][j + 1];
						fa[i - 1][j + 1][(l + a[i - 1][j + 1]) % (k + 1)] = 'R';
					}
				}
			}
		}
	}
	int ans = -1, anst = -1;
	for (int i = 0; i < m; ++i) {
		if (dp[0][i][0] > ans) {
			ans = dp[0][i][0];
			anst = i;
		}
	}
	if (ans == -1) {
		printf("-1\n");
	} else {
		int pos = anst, mod = 0;
		string path;
		for (int i = 0; i < n - 1; ++i) {
			path += fa[i][pos][mod];
			int rpos = pos;
			if (fa[i][pos][mod] == 'L') {
				++pos;
			} else {
				--pos;
			}
			mod = ((mod - a[i][rpos]) % (k + 1) + k + 1) % (k + 1);
		}
		reverse(path.begin(), path.end());
		cout << ans << endl << pos + 1 << endl << path << endl;
	}
	return 0;
}