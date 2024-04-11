#include<bits/stdc++.h>
using namespace std;
const int maxn=505,maxm=250005;
int n,m,T;
long long ans;
int vis[maxn],d[maxn][maxn],g[maxn][maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=2e9;
		for(int i=1,x,y,z;i<=m;i++)
			scanf("%d%d%d",&x,&y,&z),g[x][y]=min(g[x][y],z),g[y][x]=min(g[y][x],z);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=i==j? 0:(g[i][j]==2e9? 1e9:1);
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		/*for(int i=1;i<=n;i++)
			d[i]=1e9,vis[i]=0;
		d[1]=0,q.push(make_pair(0,1));
		while(!q.empty()){
			int x=q.top().second;
			q.pop();
			if(vis[x])
				continue;
			vis[x]=1;
			for(int i=0;i<v[x].size();i++){
				int y=v[x][i],z=w[x][i];
				if(d[y]>d[x]+1)
					d[y]=d[x]+1,q.push(make_pair(-d[y],y));
			}
		}*/
		ans=1e18;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j&&g[i][j]!=2e9){
					int res=d[1][i]+1+d[j][n];
					for(int k=1;k<=n;k++)
						res=min(res,d[1][k]+1+d[i][k]+1+d[k][n]);
					ans=min(ans,1ll*res*g[i][j]);
				}
		printf("%lld\n",ans);
	}
	return 0;
}