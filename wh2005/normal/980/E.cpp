#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
int n,k,head[N],tot;
struct pp{int nxt,to;}g[N<<1];
void add(int u,int v){
	g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;
}
int f[N][23],d[N],a[N];
void dfs(int u,int fa){
	f[u][0]=fa,d[u]=d[fa]+1;
	for(int i=head[u];i!=-1;i=g[i].nxt){
		int v=g[i].to;if(v==fa) continue;
		dfs(v,u);
	}
}
int find(int u){
	int x=u;
	for(int i=21;i>=0;i--){
		if(a[f[u][i]]==0) u=f[u][i];
	}
	return d[x]-d[u]+1;
}
int main(){
	memset(head,-1,sizeof(head));tot=0;
	scanf("%d%d",&n,&k);
	if(n==k){
		for(int i=1;i<=k;i++) printf("%d ",i);puts("");
		return 0;
	}
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);add(u,v);add(v,u);
	}
	a[n]=1;dfs(n,0);a[0]=1;
	for(int j=1;j<=21;j++)
		for(int i=1;i<=n;i++) f[i][j]=f[f[i][j-1]][j-1];
	int sum=n-k-1;
	for(int i=n-1;i>=1;i--){
		if(a[i]==1) continue;
		int x=find(i);
		if(x<=sum){
			sum-=x,a[i]=1;x=i;
			while(a[f[x][0]]==0){
				x=f[x][0],a[x]=1;
			}
		}
	}	
	for(int i=1;i<=n;i++)
		if(!a[i]) printf("%d ",i);puts("");
	return 0;
}