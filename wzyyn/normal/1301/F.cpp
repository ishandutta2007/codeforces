#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=1005,K=45;
const int dx[]={0,0,-1,1};
const int dy[]={-1,1,0,0};
int dis[K][N][N];
int vis[N][N],Vis[K];
int n,m,k,Q,a[N][N];
pii q[N*N];
vector<pii> vec[K];
void SSSP(int id){
	memset(Vis,0,sizeof(Vis));
	memset(vis,0,sizeof(vis));
	memset(dis[id],10,sizeof(dis[id]));
	int h=0,t=0; Vis[id]=1;
	for (auto i:vec[id]){
		q[++t]=i;
		vis[i.fi][i.se]=1;
		dis[id][i.fi][i.se]=0;
	}
	while (h!=t){
		int x=q[++h].fi,y=q[h].se;
		if (!Vis[a[x][y]]){
			Vis[a[x][y]]=1;
			for (auto i:vec[a[x][y]])
				if (!vis[i.fi][i.se]){
					q[++t]=i;
					vis[i.fi][i.se]=1;
					dis[id][i.fi][i.se]=dis[id][x][y]+1;
				}
		}
		For(d,0,3){
			int nx=x+dx[d],ny=y+dy[d];
			if (nx<1||nx>n||ny<1||ny>m) continue;
			if (!vis[nx][ny]){
				q[++t]=pii(nx,ny);
				vis[nx][ny]=1;
				dis[id][nx][ny]=dis[id][x][y]+1;
			}
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	For(i,1,n) For(j,1,m) scanf("%d",&a[i][j]);
	For(i,1,n) For(j,1,m) vec[a[i][j]].PB(pii(i,j));
	For(i,1,k) SSSP(i);
	scanf("%d",&Q);
	while (Q--){
		int x1,y1,x2,y2,ans;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		ans=abs(x1-x2)+abs(y1-y2);
		For(i,1,k) ans=min(ans,dis[i][x1][y1]+dis[i][x2][y2]+1);
		printf("%d\n",ans);
	}
}