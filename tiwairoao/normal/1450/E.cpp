#include <bits/stdc++.h>

const int N = 200;
const int M = 2000;

int n, m;

std::vector<int>G[N + 5]; int clr[N + 5];
void adde(int u, int v) {G[u].push_back(v), G[v].push_back(u);}
bool dfs1(int x, bool c) {
	if (clr[x] != -1) return clr[x] == c; else clr[x] = c;
	for (auto e : G[x]) if (!dfs1(e, !c)) return false;
	return true;
}
bool check_b() {
	for (int i = 1; i <= n; i++) clr[i] = -1;
	return dfs1(1, 0);
}

int f[N + 5][N + 5], u[M + 5], v[M + 5], b[M + 5];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) scanf("%d%d%d", &u[i], &v[i], &b[i]), adde(u[i], v[i]);
	if (!check_b()) {puts("NO"); return 0;}

	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) f[i][j] = (i == j ? 0 : int(1E9));
	for (int i = 1; i <= m; i++) {
		if (b[i]) {
			f[u[i]][v[i]] = (1 - clr[u[i]] + clr[v[i]]) >> 1;
			f[v[i]][u[i]] = (-1 - clr[v[i]] + clr[u[i]]) >> 1;
		} else {
			f[u[i]][v[i]] = (1 - clr[u[i]] + clr[v[i]]) >> 1;
			f[v[i]][u[i]] = (1 - clr[v[i]] + clr[u[i]]) >> 1;
		}
	}
	for (int k = n; k >= 1; k--) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
	for (int i = 1; i <= n; i++) for (int k = 1; k <= n; k++) for (int j = 1; j <= n; j++)
		if (f[i][j] > f[i][k] + f[k][j]) {puts("NO"); return 0;}
	
	puts("YES");
	int mxi = 1, mxj = 2;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		f[i][j] = (f[i][j] << 1) + (clr[i] - clr[j]);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (f[mxi][mxj] < f[i][j])
		mxi = i, mxj = j;
	printf("%d\n", f[mxi][mxj]);

	int mn = *std::min_element(f[mxi] + 1, f[mxi] + n + 1);
	for (int i = 1; i <= n; i++) printf("%d%c", f[mxi][i] - mn, i == n ? '\n' : ' ');
}