#include<bits/stdc++.h>

const int N = 100010;

std::vector <int> e[N], ans;

void dfs(int u, int fa){
	int cnt = 0;
	for (auto v : e[u]){
		if (v == fa) continue;
		++ cnt;
		dfs(v, u);
	}
	if (!cnt){
		ans.push_back(u);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0, u, v; i < n - 1; ++ i){
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++ i){
		if (e[i].size() >= 3){
			++ cnt;
		}
	}
	if (cnt >= 2){
		puts("No");
		return 0;
	}
	puts("Yes");
	for (int i = 1; i <= n; ++ i){
		if (e[i].size() >= 3 || i == n){
			dfs(i, 0);
			printf("%d\n", (int) ans.size());
			for (auto u : ans){
				printf("%d %d\n", i, u);
			}
			return 0;
		}
	}
	return 0;
}