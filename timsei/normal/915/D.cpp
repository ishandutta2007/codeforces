#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int M = 2e5 + 5;

int x , y , go[N][N] , du[N], in[N] , n , m;

bool vis[N];

void dfs(int x) {
    vis[x] = 1;
    for(int i = 1;i <= n;++ i) if(go[x][i] && !vis[i]) {
	    if(-- du[i] <= 0) dfs(i);
	}
}

int main(void) {
    scanf("%d%d" , &n , &m);
    for(int i = 1;i <= m;++ i) {
	scanf("%d%d" , &x , &y);
	go[x][y] = 1; ++ in[y];
    }
    for(int i = 1;i <= n;++ i) {
	for(int j = 1;j <= n;++ j) du[j] = in[j];
	-- du[i]; memset(vis , 0 , sizeof(vis));
	for(int j = 1;j <= n;++ j) if(du[j] <= 0 && !vis[j]) dfs(j);
	bool can = 1;
	for(int j = 1;j <= n;++ j) can &= vis[j];
	if(can) {puts("YES"); return 0;}
    }
    puts("NO");
}