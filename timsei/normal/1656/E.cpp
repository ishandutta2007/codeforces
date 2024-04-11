#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m, x, y, k, A[N], du[N], dep[N];

vector <int> G[N];

void link(int x, int y) {
	G[x].push_back(y);
	G[y].push_back(x);
}

void dfs(int x, int f) {
	dep[x] = dep[f] ^ 1;
	for(auto V : G[x]) {
		if(V == f) continue;
		dfs(V, x);
	}
}

void rmain() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) du[i] = 0, G[i].clear();
	for(int i = 1; i < n; ++ i) {
		scanf("%d%d", &x, &y);
		link(x, y);
		++ du[x], ++ du[y];
	}
	dfs(1, 0);
	int D[2] = {0, 0};
	for(int i = 1; i <= n; ++ i) {
		D[dep[i] & 1] += du[i];
	}
	
	if(D[0] == D[1]) {
		int S = 0, a = 1;
		for(int i = 1; i <= n; ++ i) {
			if(dep[i] & 1) printf("%d ", du[i]);
			else printf("%d ", -du[i]);
		}
		puts("");
		return;
	} 
}

main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}