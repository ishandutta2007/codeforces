#include<bits/stdc++.h>

const int N = 1010;

int n, m, w, dp[N][N], fa[N], _w[N], b[N], w_sum[N], b_sum[N];
std::vector <std::pair<int, int>> vec[N];

int find(int n){
	return fa[n] == n ? n : find(fa[n]);
}

void unite(int u, int v){
	int _u = find(u), _v = find(v);
	if (_u == _v)
		return;
	fa[_u] = _v;
}

int main(){
	scanf("%d%d%d", &n, &m, &w);
	for (int i = 1; i <= n; ++ i)
		scanf("%d", &_w[i]);
	for (int i = 1; i <= n; ++ i)
		scanf("%d", &b[i]);
	for (int i = 1; i <= n; ++ i)
		fa[i] = i;
	for (int i = 0, x, y; i < m; ++ i){
		scanf("%d%d", &x, &y);
		unite(x, y);
	}
	for (int i = 1; i <= n; ++ i){
		int father = find(i);
		vec[father].push_back({_w[i], b[i]});
		w_sum[father] += _w[i];
		b_sum[father] += b[i];
	}
	for (int i = 1; i <= n; ++ i)
		if (vec[i].size())
			vec[i].push_back({w_sum[i], b_sum[i]});
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i <= n; ++ i)
		dp[i][0] = 0;
	for (int i = 1; i <= n; ++ i){
		for (int j = 0; j <= w; ++ j)
			dp[i][j] = dp[i - 1][j];
		for (int j = 0; j <= w; ++ j){
			for (int k = 0; k < vec[i].size(); ++ k){
				if (dp[i - 1][j] == -1 || j + vec[i][k].first > w)
					continue;
				if (dp[i - 1][j] + vec[i][k].second > dp[i][j + vec[i][k].first])
					dp[i][j + vec[i][k].first] = dp[i - 1][j] + vec[i][k].second;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= w; ++ i)
		ans = std::max(ans, dp[n][i]);
	printf("%d\n", ans);
	return 0;
}