#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n,m,vis[1000][1000];
long long dist[1000][1000];
char str[1010][1010];

const int dy[]={-1,1,0,0},dx[]={0,0,-1,1};

int go(int y,int x) {
	return y>=0 && x>=0 && y<n && x<m;
}
void dfs1(int y,int x, int &cnt) {
	++cnt;
	vis[y][x] = 1;
	for(int k=0;k<4;k++) {
		int yy=y+dy[k], xx=x+dx[k];
		if(go(yy,xx) && !vis[yy][xx] && str[yy][xx]==str[y][x]) {
			dfs1(yy,xx,cnt);
		}
	}
}
void dfs2(int y,int x,int &cnt) {
	if(cnt==1) vis[y][x] = 0;
	else vis[y][x] = 2;
	for(int k=0;k<4;k++) {
		int yy=y+dy[k], xx=x+dx[k];
		if(go(yy,xx) && vis[yy][xx]==1) {
			dfs2(yy,xx,cnt);
		}
	}
}

void trav() {
	struct td{
		int c,y,x;
		td(int c,int y,int x):c(c), y(y), x(x) {}
		bool operatore(const td &rhs)const {
			return c>rhs.c;
		}
	};
	queue<td> que;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(vis[i][j]) {
		que.push(td(0,i,j));
	} else dist[i][j] = INF;

	if(que.empty()) {
		long long v = 1ll << 61;
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) dist[i][j] = v;
	}
	
	while(!que.empty()) {
		int y=que.front().y, x=que.front().x;
		que.pop();
		for(int k=0;k<4;k++) {
			int yy=y+dy[k],xx=x+dx[k];
			if(go(yy,xx) && !vis[yy][xx]) {
				vis[yy][xx] = 1;
				dist[yy][xx] = dist[y][x] + 1;
				que.push(td(dist[yy][xx], yy, xx));
			}
		}
	}
}

int main() {
	int test;
	scanf("%d%d%d",&n,&m,&test);
	for(int i=0;i<n;i++) scanf("%s",str[i]);

	for(int i=0;i<n;i++)for(int j=0;j<m;j++) str[i][j] -= '0';
	
	for(int i=0;i<n;i++)for(int j=0;j<m;j++) if(!vis[i][j]) {
		int cnt=0;
		dfs1(i,j,cnt);
		dfs2(i,j,cnt);
	}
	trav();

	while(test--) {
		int y,x;
		long long d;
		scanf("%d%d%lld",&y,&x,&d);
		y--; x--;
		
		printf("%lld\n", max(0ll, d-dist[y][x])%2 ^ str[y][x]);
	}

	
	return 0;
}