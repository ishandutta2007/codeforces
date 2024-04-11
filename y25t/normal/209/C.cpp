#include<cstdio>
#include<algorithm>
#define N 1000005

int n,m;

int hd[N],_hd;
struct edge{
	int v,nxt;
}e[N<<1];
inline void addedge(int u,int v){
	e[++_hd]=(edge){v,hd[u]};
	hd[u]=_hd;
}

int deg[N],cnt;

bool vis[N];
inline void dfs(int u){
	vis[u]=1;
	cnt+=deg[u]&1;
	for(int i=hd[u];i;i=e[i].nxt)
		if(!vis[e[i].v])
			dfs(e[i].v);
}

int co,ce;

int ans;

int main(){
	scanf("%d%d",&n,&m);
	if(!m){
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
		vis[i]=1;
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		deg[u]++;
		deg[v]++;
		addedge(u,v);
		addedge(v,u);
		vis[u]=vis[v]=0;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			cnt=0;
			dfs(i);
			if(!cnt){
				ans++;
				ce++;
			}
			else{
				ans+=cnt/2;
				co++;
			}
		}
	if(ce==1&&co==0&&deg[1])
		ans=0;
	if(!deg[1])
		ans++;
	printf("%d\n",ans);
}