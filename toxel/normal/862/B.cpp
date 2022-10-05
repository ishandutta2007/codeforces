#include<bits/stdc++.h>

const int N = 100010;

std::vector <int> e[N];
int dep[N];

void dfs(int u, int fa){
	for (auto v : e[u]){
		if (v == fa){
			continue;
		}
		dep[v] = dep[u] + 1;
		dfs(v, u);
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
	dfs(1, 0);
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= n; ++ i){
		++ (dep[i] & 1 ? cnt1 : cnt2);
	}
	return printf("%I64d\n", 1ll * cnt1 * cnt2 - n + 1), 0;
}