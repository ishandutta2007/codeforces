#include <cstdio>
#include <cstring>

const int N = 300000;
int n, m, e[2][N], d[N], dir[N], a[N], b[N];
bool inv[N], u[N], uu[N], wt[N];

bool done;
void dfs(int v, int pr = -1) 
{
	if (pr != -1) uu[pr] = 1;
	if (u[v]) return;
	u[v] = 1;
	for (int i = 0; i < 2; ++i) {
		if (e[i][v] == -1 || e[i][v] == pr || uu[e[i][v]]) continue;
		if (a[e[i][v]] != v) {
			inv[e[i][v]] = 1;
			dfs(a[e[i][v]], e[i][v]);
		} else {
			dfs(b[e[i][v]], e[i][v]);
		}
	}
}

bool recover(int v) 
{
	if (dir[v] != -1) {
		inv[v] = inv[v] != recover(dir[v]);
		dir[v] = -1;
	}
	return inv[v];
}

int main() 
{
	scanf("%d%d", &n, &m);
	memset(dir, -1, m << 2);
	memset(*e, -1, N << 3);
	for (int i = 0; i < m; ++i) {
		int w;
		scanf("%d%d%d", a + i, b + i, &w);
		--a[i];
		--b[i];
		d[a[i]] += w & 1;
		d[b[i]] += w & 1;
		--w;
		wt[i] = w;
		if (e[w][a[i]] != -1 && e[w][b[i]] == e[w][a[i]]) {
			inv[i] = a[i] == a[e[w][a[i]]];
			e[w][a[i]] = -1;
			e[w][b[i]] = -1;
		} else {
			if (e[w][a[i]] != -1) {
				int id = e[w][a[i]];
				e[w][a[i]] = -1;
				dir[id] = i;
				if (b[id] == a[i]) {
					a[i] = a[id];
				} else {
					inv[id] = 1;
					a[i] = b[id];
				}
			}
			if (e[w][b[i]] != -1) {
				int id = e[w][b[i]];
				e[w][b[i]] = -1;
				dir[id] = i;
				if (a[id] == b[i]) {
					b[i] = b[id];
				} else {
					inv[id] = 1;
					b[i] = a[id];
				}
			}
			e[w][a[i]] = e[w][b[i]] = i;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) ans += d[i] & 1;
	for (int i = 0; i < n; ++i) if (!u[i] && (e[0][i] == -1 || e[1][i] == -1)) dfs(i);
	for (int i = 0; i < n; ++i) if (!u[i]) dfs(i);
	printf("%d\n", ans);
	for (int i = 0; i < m; ++i) printf("%d", recover(i) + 1);
	printf("\n");
	return 0;
}