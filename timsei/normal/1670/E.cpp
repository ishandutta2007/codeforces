#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int M = N * 2;

int p, n, val[N], va[M], tot, dep[N];
vector <int> G[N], id[N];

void dfs(int x, int f) {
	dep[x] = dep[f] ^ 1;
	for(int i = 0; i < (int) G[x].size(); ++ i) {
		int V = G[x][i];
		if(V == f) continue;
		++ tot;
		if(dep[x])
		val[V] = tot,
		va[id[x][i]] = tot + (1 << p);
		else {
			val[V] = tot + (1 << p);
			va[id[x][i]] = tot;
		}
		dfs(V, x);
	}
}

void rmain() {
	scanf("%d", &p);
	n = (1 << p); tot = 0;
	for(int i = 1; i <= n; ++ i) {
		G[i].clear(); id[i].clear();
	}
	puts("1");
	for(int i = 1, x, y; i < n; ++ i) {
		scanf("%d%d", &x, &y);
		G[x].push_back(y); id[x].push_back(i);
		G[y].push_back(x); id[y].push_back(i);
	}
	val[1] = n;
	dfs(1, 0);
	for(int i = 1; i <= n; ++ i) printf("%d ", val[i]);
	puts("");
	for(int i = 1; i < n; ++ i) printf("%d ", va[i]);
	puts("");
}

main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}