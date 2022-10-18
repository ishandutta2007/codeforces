#include<cstdio>
#include<algorithm>
#define ll long long
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

bool vis[N];
inline void dfs(int u){
	vis[u]=1;
	for(int i=hd[u];i;i=e[i].nxt)
		if(!vis[e[i].v])
			dfs(e[i].v);
}

int deg[N],cnt;

inline ll C2(int x){
	return 1ll*x*(x-1)/2;
}

ll ans;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		vis[i]=1;
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		if(u==v)
			cnt++;
		else{
			deg[u]++;
			deg[v]++;
		}
		addedge(u,v);
		addedge(v,u);
		vis[u]=vis[v]=0;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			dfs(i);
			break;
		}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			puts("0");
			return 0;
		}
	ans=C2(cnt)+1ll*cnt*(m-cnt);
	for(int i=1;i<=n;i++)
		ans+=C2(deg[i]);
	printf("%lld\n",ans);
}