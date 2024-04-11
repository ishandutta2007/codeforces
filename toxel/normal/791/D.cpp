#include<bits/stdc++.h>
#define ll long long

const int N = 200010;
const int M = 5;

struct edge{
	int next, to;
};

edge e[N << 1];
int cnt[N][M], first[N], sz[N];
int n, k, e_cnt = 0;
ll ans = 0, sum[M];

void addedge(int u, int v){
	e[++ e_cnt] = {first[u], v};
	first[u] = e_cnt;
	e[++ e_cnt] = {first[v], u};
	first[v] = e_cnt;
}

void dfs(int u, int fa){
	sz[u] = 1;
	cnt[u][0] = 1;
	ll total[M] = {0};
	for (int i = first[u]; i; i = e[i].next){
		int x = e[i].to;
		if (x == fa){
			continue;
		}
		dfs(x, u);
		sz[u] += sz[x];
		for (int j = 0; j < k; ++ j){
			cnt[u][(j + 1) % k] += cnt[x][j];
			total[j] += cnt[x][j];
		}
		ans += 1ll * sz[x] * (n - sz[x]);
	}
	for (int i = first[u]; i; i = e[i].next){
		int x = e[i].to;
		if (x == fa){
			continue;
		}
		for (int j = 0; j < k; ++ j){
			total[j] -= cnt[x][j];
		}
		for (int j = 0; j < k; ++ j){
			for (int jj = 0; jj < k; ++ jj){
				sum[(j + jj + 2) % k] += total[j] * cnt[x][jj];
			}
			sum[(j + 1) % k] += cnt[x][j] << 1;
		}
		for (int j = 0; j < k; ++ j){
			total[j] += cnt[x][j];
		}
	}
}

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 0, u, v; i < n - 1; ++ i){
		scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	dfs(1, 0);
	for (int i = 1; i < k; ++ i){
		ans += (sum[i] >> 1) * (k - i);
	}
	return printf("%I64d\n", ans / k), 0;
}