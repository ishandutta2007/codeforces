#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

const int N = 2000, INF = 1000000000;
int n, m, k, s, ans[9][9], map[N][N], maxm[N + 2][N + 2];

int main() {
	scanf("%d%d%d%d", &n, &m, &k, &s);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &map[i][j]);
			--map[i][j];
		}
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			maxm[i][j] = -INF;
		}
	}
	memset(ans, 0, sizeof(ans));
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int l = 0; l < m; ++l) {
				maxm[j + 1][l + 1] = map[j][l] == i ? -j + -l : -INF;
				maxm[j + 1][l + 1] = max(maxm[j + 1][l + 1], max(maxm[j + 1][l], maxm[j][l + 1]));
				ans[i][map[j][l]] = max(ans[i][map[j][l]], j + l + maxm[j + 1][l + 1]);
			}
		}
		for (int j = 0; j < n; ++j) {
			for (int l = m - 1; l >= 0; --l) {
				maxm[j + 1][l + 1] = map[j][l] == i ? -j + l : -INF;
				maxm[j + 1][l + 1] = max(maxm[j + 1][l + 1], max(maxm[j][l + 1], maxm[j + 1][l + 2]));
				ans[i][map[j][l]] = max(ans[i][map[j][l]], j - l + maxm[j + 1][l + 1]);
			}
		}
		for (int j = n - 1; j >= 0; --j) {
			for (int l = 0; l < m; ++l) {
				maxm[j + 1][l + 1] = map[j][l] == i ? j + -l : -INF;
				maxm[j + 1][l + 1] = max(maxm[j + 1][l + 1], max(maxm[j + 2][l + 1], maxm[j + 1][l]));
				ans[i][map[j][l]] = max(ans[i][map[j][l]], -j + l + maxm[j + 1][l + 1]);
			}
		}
		for (int j = n - 1; j >= 0; --j) {
			for (int l = m - 1; l >= 0; --l) {
				maxm[j + 1][l + 1] = map[j][l] == i ? j + l : -INF;
				maxm[j + 1][l + 1] = max(maxm[j + 1][l + 1], max(maxm[j + 2][l + 1], maxm[j + 1][l + 2]));
				ans[i][map[j][l]] = max(ans[i][map[j][l]], -j + -l + maxm[j + 1][l + 1]);
			}
		}
	}
	int anst = 0, last;
	scanf("%d", &last);
	--last;
	for (int i = 1; i < s; ++i) {
		int now;
		scanf("%d", &now);
		--now;
		anst = max(anst, ans[last][now]);
		last = now;
	}
	printf("%d\n", anst);
	return 0;
}