#include<cstdio>
#define N 200005

int n,k;

int _hd,hd[N];
struct edge{
	int v,nxt;
}e[N];
inline void addedge(int u,int v){
	e[++_hd]=(edge){v,hd[u]};
	hd[u]=_hd;
}

bool vis[N];
inline int dfs(int u){
	vis[u]=1;
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(vis[v])
			continue;
		dfs(v);
	}
}

int ans;

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			dfs(i);
			ans++;
		}
	ans+=k-n;
	printf("%d",ans);
}