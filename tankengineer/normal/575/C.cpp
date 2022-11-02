#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 20 + 1;

int n;

int a[2][N][N];

int ans;

int w[N][N], u[N][N], v[N][N], p[N][N];

const int INF = 1000000000;

int minv[N], fa[N];

bool used[N];

void km(int lev) {
	int i = lev;
	lev++;
	for (int j = 0; j <= n; ++j) {
		u[lev][j] = u[i][j];
		v[lev][j] = v[i][j];
		p[lev][j] = p[i][j];
		minv[j] = INF;
		used[j] = false;
	}
	p[lev][n] = i;
	int j0 = n;
	do {
		used[j0] = true;
		int i0 = p[lev][j0], delta = INF, j1;
		for (int j = 0; j < n; ++j) {
			if (!used[j]) {
				int cur = w[i0][j] - u[lev][i0] - v[lev][j];
				if (cur < minv[j]) {
					minv[j] = cur;
					fa[j] = j0;
				}
				if (minv[j] < delta) {
					delta = minv[j];
					j1 = j;
				}
			}
		}
		for (int j = 0; j <= n; ++j) {
			if (used[j]) {
				u[lev][p[lev][j]] += delta, v[lev][j] -= delta;
			} else {
				minv[j] -= delta;
			}
		}
		j0 = j1;
	} while (p[lev][j0] != -1);
	do {
		int j1 = fa[j0];
		p[lev][j0] = p[lev][j1];
		j0 = j1;
	} while (j0 != n);
}

void go(int i, int cnt) {
	if (i == n) {
		ans = max(ans, v[i][n]);
		return;
	}
	for (int c = 0; c < 2; ++c) {
		int ncnt = cnt + c;
		if ((ncnt << 1) <= n && ((i + 1 - ncnt) << 1) <= n) {
			for (int j = 0; j < n; ++j) {
				w[i][j] = a[c][i][j];
			}
			km(i);
			go(i + 1, ncnt);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int c = 0; c < 2; ++c) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d", &a[c][i][j]);
				a[c][i][j] = -a[c][i][j];
			}
		}
	}
	ans = 0;
	for (int i = 0; i < n; ++i) {
		p[0][i] = -1;
	}
	go(0, 0);
	printf("%d\n", ans);
	return 0;
}