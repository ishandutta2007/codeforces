#include<bits/stdc++.h>

const int N = 200010;

int n, k;
int sz[N], a[N];
bool team[N];
std::vector <int> e[N];

void dfs1(int u, int fa){
	sz[u] = team[u];
	for (auto v : e[u]){
		if (v == fa){
			continue;
		}
		dfs1(v, u);
		sz[u] += sz[v];
	}
}

int dfs2(int u, int fa){
	for (auto v : e[u]){
		if (v == fa){
			continue;
		}
		if (sz[v] > k){
			return dfs2(v, u);
		}
	}
	return u;
}

int dfn = 0;

void solve(int u, int fa){
	if (team[u]){
		a[dfn ++] = u;
	}
	for (auto v : e[u]){
		if (v == fa){
			continue;
		}
		solve(v, u);
	}
}

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 0, u, v; i < n - 1; ++ i){
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 0, x; i < k << 1; ++ i){
		scanf("%d", &x);
		team[x] = true;
	}
	dfs1(1, 0);
	int v = dfs2(1, 0);
	printf("1\n%d\n", v);
	solve(v, 0);
	for (int i = 0; i < k; ++ i){
		printf("%d %d %d\n", a[i], a[i + k], v);
	}
	return 0;
}