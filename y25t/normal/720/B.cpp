#include<cstdio>
#include<algorithm>
#include<queue>
#define N 300005

int n,m;

int hd[N],_hd=1;
struct edge{
	int v,w,nxt;
}e[N<<1];
inline void addedge(int u,int v,int w){
	e[++_hd]=(edge){v,w,hd[u]};
	hd[u]=_hd;
}

int val[N],tot;

int dfn[N],_dfn,fa[N],col[N],_col;
inline void dfs(int u){
	dfn[u]=++_dfn;
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(dfn[v])
			continue;
		fa[v]=i^1;
		dfs(v);
	}
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(dfn[v]>dfn[u]||v==e[fa[u]].v)
			continue;
		col[i>>1]=++_col;
		for(int w=u;w!=v;w=e[fa[w]].v)
			col[fa[w]>>1]=_col;
	}
}

int f[N<<1];
inline int fnd(int x){
	return f[x]?f[x]=fnd(f[x]):x;
}
inline bool mrg(int x,int y){
	int fx=fnd(x),fy=fnd(y);
	if(fx==fy)
		return 0;
	f[fx]=fy;
	return 1;
}

bool a[N],b[N];

int ans;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		val[++tot]=w;
		addedge(u,v,w);
		addedge(v,u,w);
	}
	std::sort(val+1,val+tot+1);
	tot=std::unique(val+1,val+tot+1)-val-1;
	for(int i=1;i<=_hd;i++)
		e[i].w=std::lower_bound(val+1,val+tot+1,e[i].w)-val;
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			dfs(i);
	for(int i=1;i<=m;i++)
		if(!col[i])
			a[e[i<<1].w]=1;
	for(int i=1;i<=m;i++)
		if(!mrg(_col+e[i<<1].w,col[i]))
			a[e[i<<1].w]=1;
	for(int i=1;i<=tot;i++)
		if(a[i])
			b[fnd(_col+i)]=1;
	ans=tot;
	for(int i=1;i<=_col;i++)
		if(!f[i]&&!b[i])
			ans--;
	printf("%d\n",ans);
}