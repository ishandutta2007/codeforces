#include<bits/stdc++.h>
#define ll long long

const int N = 5010;
const ll INF = 0x1f1f1f1f1f1f1f1fll;

ll dp[N][N][2];
int sz[N], c[N], d[N], total, n;
std::vector <int> e[N];

void dfs(int u){
	sz[u] = 1;
	memset(dp[u], 0x1f, sizeof(dp[u]));
	dp[u][1][0] = c[u];
	dp[u][1][1] = c[u] - d[u];
	dp[u][0][1] = INF;
	dp[u][0][0] = 0;
	for (auto v : e[u]){
		dfs(v);
		for (int i = sz[u]; ~i; -- i){
			for (int j = sz[v]; ~j; -- j){
				dp[u][i + j][0] = std::min(dp[u][i + j][0], dp[u][i][0] + dp[v][j][0]);
				if (dp[u][i + j][0] > INF){
					dp[u][i + j][0] = INF;
				}
				dp[u][i + j][1] = std::min(dp[u][i + j][1], std::min(dp[u][i][1] + dp[v][j][1], dp[u][i][1] + dp[v][j][0]));
				if (dp[u][i + j][1] > INF){
					dp[u][i + j][1] = INF;
				}
			}
		}
		sz[u] += sz[v];
	}
}

int main(){
	scanf("%d%d", &n, &total);
	for (int i = 1; i <= n; ++ i){
		scanf("%d%d", &c[i], &d[i]);
		if (i > 1){
			int x;
			scanf("%d", &x);
			e[x].push_back(i);
		}
	}
	dfs(1);
	int ans = 0;
	for (int i = 0; i < N; ++ i){
		if (dp[1][i][0] <= total){
			ans = std::max(ans, i);
		}
		if (dp[1][i][1] <= total){
			ans = std::max(ans, i);
		}
	}
	return printf("%d\n", ans), 0;
}