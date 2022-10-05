#include<bits/stdc++.h>
#define ll long long
const int N = 200010;

struct edge{
	int next, to, w;
};

int first[N], a[N], cnt[N], fa[N], n, edge_cnt = 0;
ll now = 0;
edge e[N];
std::set<std::pair<ll, int>> s;

void addedge(int u, int v, int w){
	e[++ edge_cnt] = {first[u], v, w};
	first[u] = edge_cnt;
	fa[v] = u;
}

void dfs(int i){
	int sit = s.lower_bound({now - a[i], 0}) -> second;
	if (sit){
		-- cnt[fa[sit]];
		++ cnt[fa[i]];
	}
	s.insert({now, i});
	for (int j = first[i]; j; j = e[j].next){
		int x = e[j].to;
		now += e[j].w;
		dfs(x);
		now -= e[j].w;
	}
	s.erase(-- s.end());
}

void dfs1(int i){
	for (int j = first[i]; j; j = e[j].next){
		int x = e[j].to;
		dfs1(x);
		cnt[i] += cnt[x];
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
	}
	for (int i = 2, u, w; i <= n; ++ i){
		scanf("%d%d", &u, &w);
		addedge(u, i, w);
	}
	dfs(1);
	dfs1(1);
	for (int i = 1; i <= n; ++ i)
		printf("%d ", cnt[i]);
	printf("\n");
	return 0;
}