#include<bits/stdc++.h>
#define ll long long

const int N = 100010;
const int M = 25;

struct edge{
	int next, to;
};

edge e[N << 1];
int first[N], a[N], n, e_cnt = 0;
ll dp[N][M][2], ans[M], total[M], sum[M][2];

void addedge(int u, int v){
	e[++ e_cnt] = {first[u], v};
	first[u] = e_cnt;
	e[++ e_cnt] = {first[v], u};
	first[v] = e_cnt;
}

void dfs(int i, int fa){
	for (int j = first[i]; j; j = e[j].next){
		int x = e[j].to;
		if (x == fa){
			continue;
		}
		dfs(x, i);
	}
	memset(sum, 0, sizeof(sum));
	memset(total, 0, sizeof(total));
	for (int j = first[i]; j; j = e[j].next){
		int x = e[j].to;
		if (x == fa){
			continue;
		}
		for (int k = 0; k < M; ++ k){
			for (int kk = 0; kk < 2; ++ kk){
				sum[k][kk] += dp[x][k][kk];
			}
		}
	}
	for (int j = 0; j < M; ++ j){
		for (int k = 0; k < 2; ++ k){
			dp[i][j][k] += sum[j][k ^ (a[i] >> j & 1)];
		}
	}
	for (int j = 0; j < M; ++ j){
		++ dp[i][j][a[i] >> j & 1];
		ans[j] += dp[i][j][1];
	}
	for (int j = first[i]; j; j = e[j].next){
		int x = e[j].to;
		if (x == fa){
			continue;
		}
		for (int k = 0; k < M; ++ k){
			for (int kk = 0; kk < 2; ++ kk){
				for (int kkk = 0; kkk < 2; ++ kkk){
					if (kk ^ kkk ^ (a[i] >> k & 1)){
						total[k] += dp[x][k][kk] * (sum[k][kkk] - dp[x][k][kkk]);
					}
				}
			}
		}
	}
	for (int k = 0; k < M; ++ k){
		ans[k] += total[k] >> 1;
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
	}
	for (int i = 0, u, v; i < n - 1; ++ i){
		scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	dfs(1, 0);
	ll ret = 0;
	for (int i = 0; i < M; ++ i){
		ret += ans[i] << i;
	}
	printf("%I64d\n", ret);
	return 0;
}