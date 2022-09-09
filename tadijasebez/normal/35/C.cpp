#include <bits/stdc++.h>
using namespace std;
const int N=2050;
int dist[N][N];
const int inf=1e9+7;
int mv[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;scanf("%i %i",&n,&m);
	int k;scanf("%i",&k);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)dist[i][j]=inf;
	queue<int> q;
	for(int i=1;i<=k;i++){
		int x,y;scanf("%i%i",&x,&y);
		dist[x][y]=0;
		q.push(x*N+y);
	}
	while(q.size()){
		int x=q.front()/N;
		int y=q.front()%N;
		q.pop();
		for(int i=0;i<4;i++){
			int nx=x+mv[i][0];
			int ny=y+mv[i][1];
			if(dist[nx][ny]>dist[x][y]+1){
				dist[nx][ny]=dist[x][y]+1;
				q.push(nx*N+ny);
			}
		}
	}
	int ansx=1,ansy=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		if(dist[ansx][ansy]<dist[i][j]){
			ansx=i;
			ansy=j;
		}
	}
	printf("%i %i\n",ansx,ansy);
	return 0;
}