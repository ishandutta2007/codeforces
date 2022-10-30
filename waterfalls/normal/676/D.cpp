#include <bits/stdc++.h>
using namespace std;

map<char,int> rev = {
	{ '+' , 0b1111 },
	{ '-' , 0b0101 },
	{ '|' , 0b1010 },
	{ '^' , 0b0010 },
	{ '>' , 0b0001 },
	{ '<' , 0b0100 },
	{ 'v' , 0b1000 },
	{ 'L' , 0b1011 },
	{ 'R' , 0b1110 },
	{ 'U' , 0b1101 },
	{ 'D' , 0b0111 },
	{ '*' , 0b0000 }
};

struct Pos { int x,y,r; };

int n,m;
int a,b,a1,b1;
char grid[1013][1013];
int dist[1013][1013][4];

int dX[4] = {0,-1,0,1};
int dY[4] = {1,0,-1,0};

queue<Pos> frontier;

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf(" %s",&grid[i]);
	scanf("%d%d%d%d",&a,&b,&a1,&b1);
	a-=1; b-=1; a1-=1; b1-=1;
	memset(dist,-1,sizeof dist);
	dist[a][b][0] = 0;
	frontier.push({ a,b,0 });
	while (frontier.size()>0) {
		int x = frontier.front().x;
		int y = frontier.front().y;
		int r = frontier.front().r;
		frontier.pop();
		if (dist[x][y][(r+3)%4]==-1) {
			dist[x][y][(r+3)%4] = dist[x][y][r]+1;
			frontier.push({ x,y,(r+3)%4 });
		}
		for (int d=0;d<4;d++) {
			int nx = x+dX[(r+d)%4];
			int ny = y+dY[(r+d)%4];
			if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
			if (!(rev[grid[x][y]]&(1<<d))) continue;
			if (!(rev[grid[nx][ny]]&(1<<(d^2)))) continue;
			if (dist[nx][ny][r]==-1) {
				dist[nx][ny][r] = dist[x][y][r]+1;
				frontier.push({ nx,ny,r });
			}
		}
	}
	int ans = 1e9;
	for (int d=0;d<4;d++) {
		if (dist[a1][b1][d]!=-1) {
			ans = min(ans,dist[a1][b1][d]);
		}
	}
	if (ans>1e8) printf("-1\n");
	else printf("%d\n",ans);

	return 0;
}