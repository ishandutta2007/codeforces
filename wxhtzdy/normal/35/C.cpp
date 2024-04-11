#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=2050;
bool was[N][N];
int dist[N][N],dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m,k;scanf("%i%i%i",&n,&m,&k);
	deque<pair<int,int>> q;
	for(int i=1;i<=k;i++){
		int x,y;scanf("%i%i",&x,&y);
		q.pb({x,y});
		dist[x][y]=0;
		was[x][y]=true;
	}
	while(!q.empty()){
		int x=q[0].first,y=q[0].second;
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if(nx>0&&nx<=n&&ny>0&&ny<=m&&!was[nx][ny])q.pb({nx,ny}),dist[nx][ny]=dist[x][y]+1,was[nx][ny]=true;
		}
		q.pop_front();
	}
	pair<int,pair<int,int>> mx={-1,{-1,-1}};
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(dist[i][j]>=mx.first)mx.first=dist[i][j],mx.second={i,j};
	printf("%i %i",mx.second.first,mx.second.second);
	return 0;
}