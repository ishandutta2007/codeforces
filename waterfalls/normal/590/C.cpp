#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

int n,m;
char grid[1013][1013];
int dist[3][1013][1013];

int dX[4] = {-1,0,1,0};
int dY[4] = {0,-1,0,1};
const int INF = 1e8;

deque<pair<int,int> > frontier;
void bfs(int s) {
	for (int i=0;i<n;i++) for (int j=0;j<m;j++) dist[s][i][j] = INF;
	for (int i=0;i<n;i++) for (int j=0;j<m;j++) if (grid[i][j]=='1'+s) {
		frontier.push_back(MP(i,j));
		dist[s][i][j] = 0;
	}
	while (frontier.size()>0) {
		auto p = frontier.front();
		frontier.pop_front();
		int x = p.A;
		int y = p.B;
		for (int i=0;i<4;i++) {
			int nX = x+dX[i];
			int nY = y+dY[i];
			if (nX<0 || nX>=n || nY<0 || nY>=m) continue;
			if (dist[s][nX][nY]!=INF || grid[nX][nY]=='#') continue;
			int cost = (grid[nX][nY]=='.');
			dist[s][nX][nY] = dist[s][x][y]+cost;
			if (cost) frontier.push_back(MP(nX,nY));
			else frontier.push_front(MP(nX,nY));
		}
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf(" %s",&grid[i]);
	for (int i=0;i<3;i++) bfs(i);
	int ans = INF;
	for (int i=0;i<n;i++) for (int j=0;j<m;j++) {
		int cur = dist[0][i][j]+dist[1][i][j]+dist[2][i][j];
		if (grid[i][j]=='.') cur-=2;
		ans = min(ans,cur);
	}
	if (ans>=INF) printf("-1\n");
	else printf("%d\n",ans);

	return 0;
}