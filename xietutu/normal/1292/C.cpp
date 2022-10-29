#include <bits/stdc++.h>
using namespace std;

const int MaxN = 3005;

typedef pair <int, int> pii;

const long long INF = 1000000000000000ll;

int n;
int forb[MaxN][MaxN], vis[MaxN], size[MaxN][MaxN];
long long f[MaxN][MaxN];

vector <int> son[MaxN];
vector <pii> path[MaxN];

void dfs(int u, int fr, int dis) {
	vis[u] = 1; size[fr][u] = 1;
	if (u > fr) path[dis].push_back(pii(u, fr));
	for (auto v : son[u]) {
		if (vis[v]) continue;
		forb[v][fr] = u;
		dfs(v, fr, dis + 1);
		size[fr][u] += size[fr][v];
	}
	vis[u] = 0;
}

int main() {
	
//	freopen("C.in", "r", stdin);
	
	scanf("%d", &n);
	for (int i = 1; i < n; ++ i) {
		int u, v; scanf("%d%d", &u, &v);
		son[u].push_back(v);
		son[v].push_back(u);
	}
	for (int i = 1; i <= n; ++ i) {
		dfs(i, i, 0);
	}
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j) f[i][j] = - INF;
	
	for (auto ele : path[1]) {
		int u = ele.first, v = ele.second;
		f[u][v] = f[v][u] = size[u][v] * size[v][u];
	}
		
	for (int i = 1; i < n; ++ i) {
		for (auto ele : path[i]) {
			int u = ele.first, v = ele.second;
			if (f[u][v] == -INF) continue;
			for (auto uu : son[u]) {
				if (u != forb[uu][v]) continue;
				long long aim = f[u][v] + size[v][uu] * size[u][v];
				f[uu][v] = max(f[uu][v], aim);
				f[v][uu] = max(f[v][uu], aim);
			}
			
			for (auto vv : son[v]) {
				if (v != forb[vv][u]) continue;
				long long aim = f[u][v] + size[u][vv] * size[v][u];
				f[vv][u] = max(f[vv][u], aim);
				f[u][vv] = max(f[u][vv], aim);
			}
		}
	}
	
	long long ans = 0;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j) ans = max(ans, f[i][j]);
	printf("%lld\n", ans);
	
	return 0;
}