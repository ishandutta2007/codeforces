#include<bits/stdc++.h>

const int N = 100010;

int dep[N], cnt[N];
std::vector <int> e[N];

void dfs(int u){
	++ cnt[dep[u]];
	for (auto v : e[u]){
		dep[v] = dep[u] + 1;
		dfs(v);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 2, x; i <= n; ++ i){
		scanf("%d", &x);
		e[x].push_back(i);
	}
	dfs(1);
	int ans = 0;
	for (int i = 0; i < N; ++ i){
		ans += cnt[i] & 1;
	}
	printf("%d\n", ans);
	return 0;
}