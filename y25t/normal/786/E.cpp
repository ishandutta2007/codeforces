#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define N 200005
#define M 400005

namespace MF{
	int n,m,s,t;
	
	int hd[N],_hd;
	struct edge{
		int v,f,nxt;
	}e[M<<1];
	inline void addedge(int u,int v,int f){
		e[++_hd]=(edge){v,f,hd[u]};
		hd[u]=_hd;
		e[++_hd]=(edge){u,0,hd[v]};
		hd[v]=_hd;
	}
	
	int cur[N],dis[N];
	std::queue<int> q;
	inline bool bfs(int s,int t){
		for(int i=1;i<=n;i++)
			cur[i]=hd[i];
		for(int i=1;i<=n;i++)
			dis[i]=inf;
		dis[s]=0;
		q.push(s);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i=hd[u];i;i=e[i].nxt){
				int v=e[i].v,f=e[i].f;
				if(f&&dis[v]>dis[u]+1){
					dis[v]=dis[u]+1;
					q.push(v);
				}
			}
		}
		return dis[t]<inf;
	}
	inline int dfs(int u,int lmt,int t){
		if(u==t||!lmt)
			return lmt;
		int flw=0;
		for(int i=cur[u];i;i=e[i].nxt){
			cur[u]=i;
			int v=e[i].v,f=e[i].f;
			if(dis[v]!=dis[u]+1)
				continue;
			f=dfs(v,std::min(lmt,f),t);
			if(f){
				e[i].f-=f;
				e[i^1].f+=f;
				flw+=f;
				lmt-=f;
				if(!lmt)
					break;
			}
		}
		return flw;
	}
	inline int dinic(int s,int t){
		int res=0;
		while(bfs(s,t))
			res+=dfs(s,inf,t);
		return res;
	}
	
	int f[N];
	inline void init(int n_,int s_,int t_){
		for(int i=1;i<=n;i++)
			hd[i]=0;
		_hd=1;
		n=n_,s=s_,t=t_;
	}
	inline int sol(){
		return dinic(s,t);
	}
}
using MF::init;
using MF::sol;

int n,m;

int nm[N],id[N],s,t;

int hd[N],_hd;
struct edge{
	int v,id,nxt;
}e[M];
inline void addedge(int u,int v,int id){
	e[++_hd]=(edge){v,id,hd[u]};
	hd[u]=_hd;
}

int fa[N],son[N],sz[N],dep[N];
inline void dfs1(int u){
	sz[u]=1;
	dep[u]=dep[fa[u]]+1;
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==fa[u])
			continue;
		fa[v]=u;
		nm[v]=e[i].id;
		dfs1(v);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])
			son[u]=v;
	}
}
int top[N],dfn[N],_dfn,a[N];
inline void dfs2(int u){
	top[u]=u==son[fa[u]]?top[fa[u]]:u;
	dfn[u]=++_dfn;
	a[_dfn]=u;
	if(son[u])
		dfs2(son[u]);
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==fa[u]||v==son[u])
			continue;
		dfs2(v);
	}
}

int tot;

inline void build(int p,int L,int R){
	tot=std::max(tot,p);
	if(L==R){
		id[nm[a[L]]]=p;
		MF::addedge(p,t,1);
		return;
	}
	int mid=(L+R)>>1;
	MF::addedge(p,p<<1,inf);
	MF::addedge(p,p<<1|1,inf);
	build(p<<1,L,mid);
	build(p<<1|1,mid+1,R);
}
inline void ins(int p,int L,int R,int l,int r,int u){
	if(L>r||R<l)
		return;
	if(l<=L&&R<=r){
		MF::addedge(u,p,inf);
		return;
	}
	int mid=(L+R)>>1;
	ins(p<<1,L,mid,l,r,u);
	ins(p<<1|1,mid+1,R,l,r,u);
}

inline void lca_ins(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])
			std::swap(u,v);
		ins(1,1,n,dfn[top[u]],dfn[u],tot);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v])
		std::swap(u,v);
	ins(1,1,n,dfn[u]+1,dfn[v],tot);
}

std::vector<int> ans[2];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v,i);
		addedge(v,u,i);
	}
	dfs1(1);
	dfs2(1);
	s=4*n+m+1,t=s+1;
	init(4*n+m+2,s,t);
	build(1,1,n);
	for(int i=1;i<=m;i++){
		id[i+n]=++tot;
		int u,v;
		scanf("%d%d",&u,&v);
		lca_ins(u,v);
		MF::addedge(s,tot,1);
	}
	printf("%d\n",sol());
	for(int i=1;i<=m;i++)
		if(MF::dis[id[i+n]]==inf)
			ans[0].push_back(i);
	for(int i=1;i<n;i++)
		if(MF::dis[id[i]]<inf)
			ans[1].push_back(i);
	printf("%d ",ans[0].size());
	for(auto u:ans[0])
		printf("%d ",u);
	puts("");
	printf("%d ",ans[1].size());
	for(auto u:ans[1])
		printf("%d ",u);
	puts("");
}