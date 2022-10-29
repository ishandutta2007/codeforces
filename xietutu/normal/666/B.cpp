#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define PB push_back
#define F first
#define S second
const int maxn = 3005;
vector<int> G[maxn][2];
pii a[maxn][2][3];
pii Q[maxn];
int n, m, ans, c[maxn], g[maxn][maxn];
int x, y, z, w;
bool visit[maxn];
void BFS(int st, int type) {
	memset(visit, 0, sizeof visit);
	int h = 0, t = 1;
	visit[st] = true;
	Q[1] = pii(st, 0);
	while (h < t) {
		pii now = Q[++h];
		int u = now.F, d = now.S;
		for (auto v : G[u][type]) {
			if (!visit[v]) {
				if (type == 0) {
					g[st][v] = d + 1;
				}
				Q[++t] = pii(v, d + 1);
				visit[v] = true;
			}
		}
	}
	
	Q[0] = Q[1] = pii(st, -100000000);
	a[st][type][0] = Q[t];
	a[st][type][1] = Q[t - 1];
	a[st][type][2] = t > 1 ? Q[t - 2] : pii(st, -100000000);
}
inline void update(int s, int a, int b, int c, int d) {
	if (s > ans) {
		ans = s;
		x = a; y = b; z = c; w = d;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u][0].PB(v);
		G[v][1].PB(u);
	}
	
	for (int i = 1; i <= n; ++i) {
		BFS(i, 0);
		BFS(i, 1);
	}
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i != j && g[i][j]) {
				for (int k = 0; k < 3; ++k) {
					if (a[i][1][k].F == j || a[i][1][k].F == i) continue;
					for (int l = 0; l < 3; ++l) {
						if (a[j][0][l].F == j || a[j][0][l].F == i) continue;
						if (a[i][1][k].F != a[j][0][l].F) {
							update(a[i][1][k].S + a[j][0][l].S + g[i][j], a[i][1][k].F, i, j, a[j][0][l].F);
						}
					}
				}
			}
	
	printf("%d %d %d %d\n", x, y, z, w);
}