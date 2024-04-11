#include <cstdio>
#include <cstring>
#include <algorithm>
int n,m,M,x,y,col[505],C[505][505],f[505][505];
char s[505];
int dfs(int x,int y) {
	if (f[x][y] != -1) return f[x][y];
	if (x == 0 && y == 0) return 1;
	f[x][y] = 0;
	if (x >= 2) f[x][y] = (f[x][y] + (long long)(dfs(x - 2,y)) * C[x][2] % M ) % M;
	if (y >= 2) f[x][y] = (f[x][y] + (long long)(dfs(x + 2,y - 2)) * C[y][2] % M ) % M;
	if (x >= 1 && y >= 1) f[x][y] = (f[x][y] + (long long)(dfs(x,y - 1)) * x % M * y % M) % M;
	return f[x][y];
}
int main() {
	scanf("%d%d%d",&n,&m,&M);
	for (int i = 1; i <= n; ++i) {
		C[i][i] = C[i][0] = 1;
		for (int j = 1; j < i; ++j)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % M;
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%s",s + 1);
		for (int j = 1; j <= n; ++j)
			if (s[j] == '1') ++col[j];
	}
	bool bo = true;
	for (int i = 1; i <= n; ++i) {
		if (col[i] == 1) ++x;
		else if (col[i] == 0) ++y;
		else if (col[i] > 2) bo = false;
	}
	memset(f,255,sizeof(f));
	if (!bo) printf("0\n");
	else printf("%d\n",dfs(x,y)); 
}