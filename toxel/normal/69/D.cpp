#include<bits/stdc++.h>

inline int sqr(int x){return x * x;}

const int N = 210;

int d;
bool vis[N << 1][N << 1][2][2][2];
bool dp[N << 1][N << 1][2][2][2];
std::vector <std::pair <int, int>> vec;

void dfs(int x, int y, int used0, int used1, int turn){
	if (vis[x + N][y + N][used0][used1][turn]) return;
	vis[x + N][y + N][used0][used1][turn] = true;
	for (auto u : vec){
		int xx = x + u.first;
		int yy = y + u.second;
		if (sqr(xx) + sqr(yy) <= sqr(d)){
			dfs(xx, yy, used0, used1, turn ^ 1);
			if (!dp[xx + N][yy + N][used0][used1][turn ^ 1]){
				dp[x + N][y + N][used0][used1][turn] = true;
				break;
			}
		}
	}
	if (turn){
		if (!used1){
			dfs(y, x, used0, 1, 0);
			if (!dp[y + N][x + N][used0][1][0]){
				dp[x + N][y + N][used0][0][1] = true;
			}
		}
	}
	else{
		if (!used0){
			dfs(y, x, 1, used1, 1);
			if (!dp[y + N][x + N][1][used1][1]){
				dp[x + N][y + N][0][used1][0] = true;
			}
		}
	}
}

int main(){
	int x, y, n;
	scanf("%d%d%d%d", &x, &y, &n, &d);
	for (int i = 0, u, v; i < n; ++ i){
		scanf("%d%d", &u, &v);
		vec.push_back({u, v});
	}
	dfs(x, y, 0, 0, 0);
	puts(dp[x + N][y + N][0][0][0] ? "Anton" : "Dasha");
	return 0;
}