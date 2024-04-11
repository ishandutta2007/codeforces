#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 3030, inf = 1e9 + 7;
int n, m; vector <int> E[MAXN];
int dis[MAXN][MAXN]; queue <int> q;
int mxin[MAXN][4], mxout[MAXN][4];

int main () {
	n = read(), m = read(); int i, j;
	for (i = 1; i <= m; i++) {
		int u = read(), v = read();
		E[u].emplace_back(v);
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) dis[i][j] = inf;
		dis[i][i] = 0, q.push(i);
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (auto v: E[x]) if (dis[i][v] > dis[i][x] + 1)
				dis[i][v] = dis[i][x] + 1, q.push(v);
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (dis[j][i] != inf) {
				for (int k = 0; k < 4; k++) if (dis[j][i] >= dis[mxin[i][k]][i]){
					for (int kk = 3; kk > k; kk--) mxin[i][kk] = mxin[i][kk - 1];
					mxin[i][k] = j; break;
				}
			}
			if (dis[i][j] != inf) {
				for (int k = 0; k < 4; k++) if (dis[i][j] >= dis[i][mxout[i][k]]){
					for (int kk = 3; kk > k; kk--) mxout[i][kk] = mxout[i][kk - 1];
					mxout[i][k] = j; break;
				}
			}
		}
	}
	int A, B, C, D, ans = -1;
	for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) if (i != j && dis[i][j] != inf) {
		for (int pp = 0; pp < 4 && mxin[i][pp]; pp++) for (int qq = 0; qq < 4 && mxout[j][qq]; qq++) {
			const int p = mxin[i][pp], q = mxout[j][qq];
			if (dis[p][i] != inf && dis[j][q] != inf && p != q && p != i && p != j && q != i && q != j) {
				const int val = dis[p][i] + dis[i][j] + dis[j][q];
				if (val > ans) ans = val, A = p, B = i, C = j, D = q;
			}
		}
	}
	// for (i = 1; i <= n; i++) {
	// 	printf("node %d\n", i);
	// 	for (int j = 0; j < 4; j++) {
	// 		printf("in %d | out %d\n", mxin[i][j], mxout[i][j]);
	// 	}
	// }
	printf("%d %d %d %d\n", A, B, C, D);
	// printf("%d\n", ans);
	return 0;
}