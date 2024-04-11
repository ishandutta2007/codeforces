#include <bits/stdc++.h>

using std::abs;

const int INF = int(1E9) + 5;

void chkmin(int &x, const int &y) {x = std::min(x, y);}
void chkmax(int &x, const int &y) {x = std::max(x, y);}

int f[1 << 14][105], g[1 << 14][105];

int xa[14], ya[14], n, m, s;
struct node{int xb, yb, t;}b[105];
int main() {
	scanf("%d%d", &n, &m), s = (1 << n);
	for (int i = 0; i < n; i++) scanf("%d%d", &xa[i], &ya[i]);
	for (int i = 0; i < m; i++) scanf("%d%d%d", &b[i].xb, &b[i].yb, &b[i].t);
	std::sort(b, b + m, [](const node &p, const node &q){return p.t < q.t;});

	for (int i = 0; i < s; i++) for (int j = 0; j < m; j++)
		f[i][j] = INF, g[i][j] = -INF;
	for (int i = 0; i < m; i++) g[0][i] = 1;
	for (int i = 0; i < n; i++) f[1 << i][0] = 0;
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < m; j++) {
			int d = INF;
			for (int k = 0; k < n; k++) if ((i >> k) & 1)
				d = std::min(d, abs(xa[k] - b[j].xb) + abs(ya[k] - b[j].yb));
			for (int k = 0; k < m; k++) if (f[i][k] + d <= b[j].t)
				chkmax(g[i][j], k + 1);

			for (int k = 0; k < j; k++)
				if (b[k].t + abs(b[k].xb - b[j].xb) + abs(b[k].yb - b[j].yb) <= b[j].t)
					chkmax(g[i][j], g[i][k] + 1);
			
			if (g[i][j] >= 0) chkmin(f[i][g[i][j]], b[j].t);
		}

		for (int k = 0; k < n; k++) if (!((i >> k) & 1)) {
			int d = INF;
			for (int j = 0; j < n; j++) if ((i >> j) & 1)
				d = std::min(d, abs(xa[k] - xa[j]) + abs(ya[k] - ya[j]));
			for (int j = 0; j < m; j++) chkmin(f[i | (1 << k)][j], f[i][j] + d);

			for (int j = 0; j < m; j++) if (g[i][j] >= 0) {
				d = abs(xa[k] - b[j].xb) + abs(ya[k] - b[j].yb);
				chkmin(f[i | (1 << k)][g[i][j]], b[j].t + d);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < s; i++) for (int j = 0; j < m; j++)
		ans = std::max(ans, g[i][j]);
	printf("%d\n", ans);
}