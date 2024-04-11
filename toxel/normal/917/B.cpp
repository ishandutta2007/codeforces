#include<bits/stdc++.h>

const int N = 110;
const int M = 30;

bool sg[N][N][M];
bool vis[N][N];
char s[N];
std::vector <std::pair <int, int>> vec[N];

void dfs(int x, int y){
	if (vis[x][y]) return;
	vis[x][y] = true;
	for (auto v : vec[x]){
		dfs(y, v.first);
		for (int i = 0; i <= v.second; ++ i){
			if (!sg[y][v.first][v.second]){
				sg[x][y][i] = true;
			}
		}
	}
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0, u, v; i < m; ++ i){
		scanf("%d%d%s", &u, &v, s);
		vec[u].push_back({v, s[0] - 'a'});
	}
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= n; ++ j){
			dfs(i, j);
			putchar(sg[i][j][0] ? 'A' : 'B');
		}
		putchar('\n');
	}
	return 0;
}