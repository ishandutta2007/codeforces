#include<bits/stdc++.h>

const int N = 500010;

std::set <int> total;
std::set <int> set[N];
std::vector <int> e[N];
int col[N];
int n, m;

void dfs(int u, int fa){
	for (auto v : set[u]){
		if (set[fa].count(v)){
			total.erase(col[v]);
		}
	}
	for (auto v : set[u]){
		if (!set[fa].count(v)){
			col[v] = *(total.begin());
			total.erase(total.begin());
		}
	}
	for (auto v : set[u]){
		total.insert(col[v]);
	}
	for (auto v : e[u]){
		if (v == fa){
			continue;
		}
		dfs(v, u);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1, x; i <= n; ++ i){
		scanf("%d", &x);
		for (int j = 0, y; j < x; ++ j){
			scanf("%d", &y);
			set[i].insert(y);
		}
	}
	for (int i = 0, u, v; i < n - 1; ++ i){
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1; i <= m; ++ i){
		total.insert(i);
	}
	dfs(1, 0);
	int max = 0;
	for (int i = 1; i <= m; ++ i){
		if (!col[i]){
			col[i] = 1;
		}
		max = std::max(max, col[i]);
	}
	printf("%d\n", max);
	for (int i = 1; i <= m; ++ i){
		printf("%d%c", col[i], " \n"[i == m]);
	}
	return 0;
}