#include <bits/stdc++.h>
using namespace std;

int n,m,k;
char grid[1013][1013];
int visited[1013][1013][2];

int dX[4] = {-1,0,1,0};
int dY[4] = {0,-1,0,1};

int dfs(int x, int y, int val=0) {
	if (val>0) visited[x][y][1] = val;
	visited[x][y][0] = 1;
	int res = 0;
	for (int i=0;i<4;i++) {
		int nX = x+dX[i], nY = y+dY[i];
		if (grid[nX][nY]!='.') res+=1;
		else if (!visited[nX][nY][val>0]) res+=dfs(nX,nY,val);
	}
	return res;
}

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<n;i++) scanf(" %s",&grid[i]);
	for (int i=0;i<n;i++) for (int j=0;j<m;j++) if (grid[i][j]=='.' && !visited[i][j][0]) dfs(i,j,dfs(i,j));
	for (int i=0;i<k;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",visited[x-1][y-1][1]);
	}

	return 0;
}