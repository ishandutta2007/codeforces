#include<bits/stdc++.h>

const int N = 200010;

int dep[N], ans = 0, max[N];
bool exist[N];
std::vector <int> e[N];
int n, x;
bool vis[N];

void dfs(int u, int fa){
	max[u] = dep[u];
	for (auto v : e[u]){
		if (v == fa){
			continue;
		}
		dep[v] = dep[u] + 1;
		dfs(v, u);
		if (exist[v]){
			exist[u] = true;
		}
		max[u] = std::max(max[u], max[v]);
	}
}

void dfs1(int u, int fa){
	for (auto v : e[u]){
		if (v == fa || !exist[v]){
			continue;
		}
		if (dep[v] - dep[1] > dep[x] - dep[v]){
			ans = std::max(ans, max[v]);
		}
		dfs1(v, u);
	}
}

int main(){
	scanf("%d%d", &n, &x);
	for (int i = 0, u, v; i < n - 1; ++ i){
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	exist[x] = true;
	dfs(1, 0);
	dfs1(1, 0);
	return printf("%d\n", ans << 1), 0;
}