#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x3f3f3f3f
#define N 205
#define M N*N/2

int n,m;

struct Edge{
	int u,v,w;
}E[M];

int dis[N][M];

int val[N],rk[N][N];
inline bool cmp(int x,int y){
	return val[x]<val[y];
}

int ans;

int main(){
	scanf("%d%d",&n,&m);
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		dis[u][v]=dis[v][u]=std::min(dis[u][v],w);
		E[i]=(Edge){u,v,w};
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=std::min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			rk[i][j]=j;
			val[j]=dis[i][j];
		}
		std::sort(rk[i]+1,rk[i]+n+1,cmp);
	}
	ans=inf;
	for(int i=1;i<=n;i++)
		ans=std::min(ans,2*dis[i][rk[i][n]]);
	for(int i=1;i<=m;i++){
		int u=E[i].u,v=E[i].v,w=E[i].w;
		for(int i=n-1,j=n;i;i--)
			if(dis[v][rk[u][j]]<dis[v][rk[u][i]]){
				ans=std::min(ans,dis[u][rk[u][i]]+dis[v][rk[u][j]]+w);
				j=i;
			}
	}
	printf("%lf\n",(double)ans/2.0);
}