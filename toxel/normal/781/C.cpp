#include<bits/stdc++.h>

const int N = 200010;


struct edge{
	int next, to;
};

int first[N], col[N], n, m, k, e_cnt = 0;
edge e[N << 1];
bool vis[N];
std::vector <int> vec, ans[N];

void addedge(int u, int v){
	e[++ e_cnt] = {first[u], v};
	first[u] = e_cnt;
	e[++ e_cnt] = {first[v], u};
	first[v] = e_cnt;
}

void dfs(int u){
	vec.push_back(u);
	vis[u] = true;
	bool flag = false;
	for (int i = first[u]; i; i = e[i].next){
		int x = e[i].to;
		if (vis[x]){
			continue;
		}
		flag = true;
		dfs(x);
		vec.push_back(u);
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0, u, v; i < m; ++ i){
		scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	dfs(1);
	for (int i = 0; i < k; ++ i){
		bool flag = false;
		for (int j = 0, sz = (2 * n + k - 1) / k; j < sz; ++ j){
			if (i * sz + j >= vec.size()){
				flag = true;
				break;
			}
			ans[i].push_back(vec[i * sz + j]);
		}
		if (flag){
			break;
		}
	}
	for (int i = 0; i < k; ++ i){
		if (!ans[i].size()){
			ans[i].push_back(1);
		}
		printf("%d ", ans[i].size());
		for (auto u : ans[i]){
			printf("%d ", u);
		}
		printf("\n");
	}
	return 0;
}