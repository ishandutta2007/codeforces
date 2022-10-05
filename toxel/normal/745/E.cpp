#include<bits/stdc++.h>

const int N = 16;

int dp[1 << N][N * N], n, c[N], r[N], b[N], max[1 << N], min[1 << N], vis[1 << N];

void solve(int state){
	if (vis[state]){
		return;
	}
	int col[2] = {0, 0};
	for (int i = 0; i < n; ++ i){
		if (state >> i & 1){
			++ col[c[i]];
		}
	}
	for (int i = 0; i < n; ++ i){
		if (state >> i & 1){
			-- col[c[i]];
			int x = state ^ 1 << i;
			solve(x);
			for (int j = min[x]; j <= max[x]; ++ j){
				int y = std::min(col[0], r[i]), z = std::min(col[1], b[i]);
				dp[state][y + j] = std::max(dp[state][y + j], dp[x][j] + z);
				max[state] = std::max(max[state], y + j);
				min[state] = std::min(min[state], y + j);
			}
			++ col[c[i]];
		}
	}
	vis[state] = true;
}

int main(){
	memset(min, 0x7f, sizeof(min));
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		char s[10];
		scanf("%s%d%d", s, &r[i], &b[i]);
		if (s[0] == 'B'){
			c[i] = 1;
		}
	}
	int x = (1 << n) - 1;
	min[0] = 0;
	vis[0] = true;
	solve(x);
	int col[2] = {0, 0};
	for (int i = 0; i < n; ++ i){
		col[0] += r[i];
		col[1] += b[i];
	}
	int ans = INT_MAX;
	for (int i = min[x]; i <= max[x]; ++ i){
		col[0] -= i;
		col[1] -= dp[x][i];
		ans = std::min(ans, std::max(col[0], col[1]));
		col[0] += i;
		col[1] += dp[x][i];
	}
	return printf("%d\n", ans + n), 0;
}