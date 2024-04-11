#include <bits/stdc++.h>
using namespace std;

int n,m;
char grid[1013][1013];
int sz[1013][1013];
int num[1013][1013];
char ans[1013][1013];
int has[1000013];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

void dfs1(int x, int y) {
	sz[x][y] = 1;
	for (int i=0;i<4;i++) {
		int nx = x+dx[i];
		int ny = y+dy[i];
		if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
		if (grid[nx][ny]=='*' || sz[nx][ny]) continue;
		dfs1(nx,ny);
		sz[x][y]+=sz[nx][ny];
	}
}

void dfs2(int x, int y, int s, int id) {
	sz[x][y] = s;
	num[x][y] = id;
	for (int i=0;i<4;i++) {
		int nx = x+dx[i];
		int ny = y+dy[i];
		if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
		if (grid[nx][ny]=='*' || num[nx][ny]) continue;
		dfs2(nx,ny,s,id);
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf(" %s",&grid[i]);
	int on = 1;
	for (int x=0;x<n;x++) for (int y=0;y<m;y++) {
		if (!num[x][y] && grid[x][y]=='.') {
			dfs1(x,y);
			dfs2(x,y,sz[x][y],on++);
		}
	}
	for (int x=0;x<n;x++) for (int y=0;y<m;y++) {
		if (grid[x][y]=='*') {
			int res = 1;
			for (int i=0;i<4;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
				if (grid[nx][ny]=='*' || has[num[nx][ny]]) continue;
				has[num[nx][ny]] = 1;
				res+=sz[nx][ny];
			}
			for (int i=0;i<4;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
				has[num[nx][ny]] = 0;
			}
			ans[x][y] = '0'+res%10;
		} else ans[x][y] = '.';
	}
	for (int i=0;i<n;i++) printf("%s\n",ans[i]);

	return 0;
}