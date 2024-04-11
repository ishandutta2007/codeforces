/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <unordered_map>
#include <random>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (ll)n; i++)
#define mp make_pair
#define ui unsigned ll

using namespace std;

const int maxn = 1010, maxlog = 10;
int v[maxn][maxn];
int sum[maxn][maxn];

int get_sum(int lx, int rx, int ly, int ry) {
	return sum[rx][ry] - sum[rx][ly - 1] - sum[lx - 1][ry] + sum[lx - 1][ly - 1];
}

int ans[maxn][maxn];
int st[maxn][maxn][maxlog];
int p[maxn];
int b[maxn];

int tr[maxn][maxn][maxlog][maxlog];

int go(int x, int ds, int l, int r) {
	int d = p[r - l + 1];

	return max(tr[x][l][ds][d], tr[x][r - (1 << d) + 1][ds][d]);
}

int main() {
	for (int i = 0; (1 << i) < maxn; i++) {
		p[1 << i] = i;
	}

	for (int i = 1; i < maxn; i++) {
		if (p[i] == 0) {
			p[i] = p[i - 1];
		}
	}

	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &v[i][j]);
			sum[i][j] = v[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int l = 0, r = min(n - i + 1, m - j + 1);

			while (l != r) {
				int mm = (l + r + 1) >> 1;

				if (get_sum(i, i + mm - 1, j, j + mm - 1) == mm * mm) {
					l = mm;
				} else {
					r = mm - 1;
				}
			}

			ans[i][j] = l;
		}
	}

	for (int i = 0; i < maxlog; i++) {
		for (int x = 1; x <= n - (1 << i) + 1; x++) {
			for (int y = 1; y <= m; y++) {
				if (i != 0) {
					st[x][y][i] = max(st[x][y][i - 1], st[x + (1 << (i - 1))][y][i - 1]);
				} else {
					st[x][y][0] = ans[x][y];
				}
			}
		}
	}

	for (int i = 0; i < maxlog; i++) {
		for (int x = 1; x <= n - (1 << i) + 1; x++) {
			
			for (int y = 1; y <= m; y++) {
				b[y] = st[x][y][i];
			}

			for (int it = 0; it < maxlog; it++) {
				for (int y = 1; y <= m - (1 << it) + 1; y++) {
					if (it == 0) {
						tr[x][y][i][it] = b[y];
					} else {
						tr[x][y][i][it] = max(tr[x][y][i][it - 1], tr[x][y + (1 << (it - 1))][i][it - 1]);
					}
				}
			}
		}
	}

	int q;

	cin >> q;

	while (q--) {
		int a, b, c, d;

		scanf("%d %d %d %d", &a, &b, &c, &d);

		int l = 0;
		int r = min(c - a + 1, d - b + 1);

		while (l != r) {
			int mm = (l + r + 1) >> 1;
			int lm = a;
			int rm = c - mm + 1;

			int ds = p[rm - lm + 1];

			int now = go(lm, ds, b, d - mm + 1);
			now = max(now, go(rm - (1 << ds) + 1, ds, b, d - mm + 1));

			if (now >= mm) {
				l = mm;
			} else {
				r = mm - 1;
			}
		}

		printf("%d\n", l);
	}

	return 0;
}