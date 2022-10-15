#include "bits/stdc++.h"
using namespace std;

const int maxn=2007;
const int INF=10007;
int n,m,s,t;
int g[maxn][maxn];
int ds[maxn],dt[maxn];

void dijkstra(int u,int d[]){
	bool v[maxn];
	memset(v,0,sizeof(v));
	for (int i=1;i<=n;++i){
		d[i]=INF;
	}
	int x=u;
	d[u]=0;
	for (int i=1;i<=n;++i){
		v[x]=1;
		int k=-1;
		for (int j=1;j<=n;++j){
			if (v[j]) continue;
			if (d[j]>d[x]+g[x][j]){
				d[j]=d[x]+g[x][j];
			}
			if (k==-1||d[j]<d[k]){
				k=j;
			}
		}
		x=k;
	}
}

int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			g[i][j]=INF;	
		}
	}
	for (int i=1;i<=m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u][v]=g[v][u]=1;
	}
	dijkstra(s,ds);
	dijkstra(t,dt);
	int ans=ds[t],sum=0;
	for (int i=1;i<=n;++i){
		for (int j=i+1;j<=n;++j){
			if (ds[i]+dt[j]+1>=ans&&ds[j]+dt[i]+1>=ans&&g[i][j]!=1){
				sum++;
			}
		}
	}
	printf("%d\n",sum);
	return 0;
}