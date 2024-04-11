#include <bits/stdc++.h>
using namespace std;

int n,k;
char grid[3][113];
bool can[3][113];

int main() {
	int T;
	scanf("%d",&T);
	for (int t=0;t<T;t++) {
		scanf("%d%d",&n,&k);
		memset(grid,'.',sizeof grid);
		for (int i=0;i<3;i++) {
			scanf(" %s",&grid[i]);
			grid[i][n] = '.';
		}
		memset(can,0,sizeof can);
		for (int i=0;i<3;i++) if (grid[i][0]=='s') can[i][0] = 1;
		for (int j=0;j<113-3;j+=3) for (int i=0;i<3;i++) if (can[i][j]) {
			if (grid[i][j+1]=='.' && grid[i][j+2]=='.' && grid[i][j+3]=='.') can[i][j+3] = 1;
			if (i>0 && grid[i][j+1]=='.' && grid[i-1][j+1]=='.' && grid[i-1][j+2]=='.' && grid[i-1][j+3]=='.') can[i-1][j+3] = 1;
			if (i<2 && grid[i][j+1]=='.' && grid[i+1][j+1]=='.' && grid[i+1][j+2]=='.' && grid[i+1][j+3]=='.') can[i+1][j+3] = 1;
		}
		bool ok = 0;
		for (int i=0;i<3;i++) if (can[i][111]) ok = 1;
		printf("%s\n",ok ? "YES" : "NO");
	}

	return 0;
}