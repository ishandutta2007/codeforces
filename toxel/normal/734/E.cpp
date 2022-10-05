#include <bits/stdc++.h>

#define MAXN (200010)

int n, ans;
int u[MAXN], v[MAXN], dp[MAXN], fa[MAXN], col[MAXN];
std::vector<int> g[MAXN];
std::set <std::pair <int, int>> set;

void build(){
	for (int i = 0; i < MAXN; ++ i){
		fa[i] = i;
	}
}

int find(int u){
	return fa[u] == u ? u : fa[u] = find(fa[u]);
}

void unite(int u, int v){
	int _u = find(u), _v = find(v);
	if (_u == _v){
		return;
	}
	fa[_u] = _v;
	find(u);
}

void dfs(int u, int fa){
	int max1 = 0, max2 = 0;
	for(auto v : g[u]){
		if(v == fa) continue;
		dfs(v, u);
		if(max1 <= dp[v]){
			max2 = max1;
			max1 = dp[v];
		}
		else if(max2 < dp[v]){
			max2 = dp[v];
		}
	}
	dp[u] = max1 + 1;
	ans = std::max(ans, max1 + max2);
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &col[i]);
	}
	build();
	for(int i = 1; i < n; ++ i){
		scanf("%d%d", &u[i], &v[i]);
		if (col[u[i]] == col[v[i]]){
			unite(u[i], v[i]);
		}
	}
	for (int i = 1; i < n; ++ i){
		find(u[i]), find(v[i]);
		int x = fa[u[i]], y = fa[v[i]];
		if (x != y && !set.count({x, y})){
			g[x].push_back(y);
			g[y].push_back(x);
			set.insert({x, y});
			set.insert({y, x});
		}
	}
	dfs(fa[1], 0);
	printf("%d\n", ans + 1 >> 1);
	return 0;
}