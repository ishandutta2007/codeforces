#include<bits/stdc++.h>
#define ll long long
#define N 505

int T;

int n,m,b[N*N][3];

int d[N][N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
			d[i][j]=i==j?0:1e9;
		for(int i=1;i<=m;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			d[u][v]=d[v][u]=1;
			b[i][0]=u,b[i][1]=v,b[i][2]=w;
		}
		for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
			d[i][j]=std::min(d[i][j],d[i][k]+d[k][j]);
		ll ans=1e18;
		for(int i=1;i<=m;i++){
			int u=b[i][0],v=b[i][1],w=b[i][2];
			ans=std::min(ans,1ll*w*(d[u][1]+d[v][n]+1));
			ans=std::min(ans,1ll*w*(d[u][n]+d[v][1]+1));
			for(int x=1;x<=n;x++){
				ans=std::min(ans,1ll*w*(d[u][x]+d[1][x]+d[n][x]+2));
				ans=std::min(ans,1ll*w*(d[v][x]+d[1][x]+d[n][x]+2));
			}
		}
		printf("%lld\n",ans);
	}
}