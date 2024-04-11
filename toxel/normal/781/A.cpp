#include<bits/stdc++.h>

const int N = 200010;

struct edge{
	int next, to;
};

int first[N], col[N], n, max = 1, e_cnt = 0;
edge e[N << 1];

void addedge(int u, int v){
	e[++ e_cnt] = {first[u], v};
	first[u] = e_cnt;
	e[++ e_cnt] = {first[v], u};
	first[v] = e_cnt;
}

void dfs(int u, int fa){
	int color = 1;
	for (int i = first[u]; i; i = e[i].next){
		int v = e[i].to;
		if (v == fa){
			continue;
		}
		while (color == col[fa] || color == col[u]){
			++ color;
		}
		max = std::max(max, color);
		col[v] = color ++;
		dfs(v, u);
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 0, u, v; i < n - 1; ++ i){
		scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	col[1] = 1;
	dfs(1, 0);
	printf("%d\n", max);
	for (int i = 1; i <= n; ++ i){
		printf("%d ", col[i]);
	}
	return printf("\n"), 0;
}