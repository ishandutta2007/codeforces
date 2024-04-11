#include<bits/stdc++.h>

const int N = 310;
const int M = 100010;
const int moder = 1e9 + 7;

std::vector <int> e[N];
int cnt = 0;
int ord[N];
bool vis[N];
int a[N];
int dp[M], ddp[M];

void dfs(int u){
	vis[u] = true;
	for (auto v : e[u]){
		if (!vis[v]){
			dfs(v);
		}
	}
	if (!e[u].empty()){
		a[u] += a[e[u][0]];
	}
	ord[u] = ++ cnt;
}

int main(){
	int n, q, t;
	scanf("%d%d%d", &n, &q, &t);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
	}
	while (q --){
		int u, v;
		scanf("%d%d", &u, &v);
		e[v].push_back(u);
	}
	for (int i = 1; i <= n; ++ i){
		if (!vis[i]){
			dfs(i);
		}
	}
	for (int i = 1; i <= n; ++ i){
		for (auto u : e[i]){
			if (ord[i] <= ord[u]){
				return printf("0\n"), 0;
			}
		}
	}
	for (int i = 1; i <= n; ++ i){
		for (auto u : e[i]){
			t -= a[u];
			if (t < 0){
				return printf("0\n"), 0;
			}
		}
	}
	dp[0] = 1;
	for (int i = 1; i <= n; ++ i){
		memcpy(ddp, dp, sizeof(dp));
		for (int j = 0; j < M; ++ j){
			int x = j + a[i];
			if (x >= M) break;
			dp[x] += dp[j];
			dp[x] -= dp[x] >= moder ? moder : 0;
		}
	}
	return printf("%d\n", dp[t]), 0;
}