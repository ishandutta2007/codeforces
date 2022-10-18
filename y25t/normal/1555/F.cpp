#include<bits/stdc++.h>
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define N 300005
#define M 500005

int n,m;
std::vector<std::pair<pii,pii>> a;

int f[N];
inline int fnd(int x){
	return f[x]?f[x]=fnd(f[x]):x;
}

int hd[N],_hd;
struct edge{
	int v,w,nxt;
}e[N<<1];
inline void addedge(int u,int v,int w){
	e[++_hd]=(edge){v,w,hd[u]};
	hd[u]=_hd;
}

struct node{
	int mx,add;
}t[N<<2];
inline void pshd(int p){
	t[p<<1].mx+=t[p].add;
	t[p<<1].add+=t[p].add;
	t[p<<1|1].mx+=t[p].add;
	t[p<<1|1].add+=t[p].add;
	t[p].add=0;
}
inline void add(int p,int L,int R,int l,int r,int d){
	if(L>r||R<l)
		return;
	if(l<=L&&R<=r){
		t[p].mx+=d;
		t[p].add+=d;
		return;
	}
	pshd(p);
	int mid=(L+R)>>1;
	add(p<<1,L,mid,l,r,d);
	add(p<<1|1,mid+1,R,l,r,d);
	t[p].mx=std::max(t[p<<1].mx,t[p<<1|1].mx);
}
inline int mx(int p,int L,int R,int l,int r){
	if(L>r||R<l)
		return 0;
	if(l<=L&&R<=r)
		return t[p].mx;
	pshd(p);
	int mid=(L+R)>>1;
	return std::max(mx(p<<1,L,mid,l,r),mx(p<<1|1,mid+1,R,l,r));
}

int fa[N],son[N],sz[N],dep[N],s[N];
inline void dfs1(int u){
	dep[u]=dep[fa[u]]+1;
	sz[u]=1;
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==fa[u])
			continue;
		fa[v]=u;
		s[v]=s[u]^e[i].w;
		dfs1(v);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])
			son[u]=v;
	}
}
int top[N],dfn[N],_dfn;
inline void dfs2(int u){
	top[u]=u==son[fa[u]]?top[fa[u]]:u;
	dfn[u]=++_dfn;
	if(son[u])
		dfs2(son[u]);
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==fa[u]||v==son[u])
			continue;
		dfs2(v);
	}
}

inline void lca_add(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])
			std::swap(u,v);
		add(1,1,n,dfn[top[u]],dfn[u],1);
		u=fa[top[u]];
	}
	if(dep[u]<dep[v])
		std::swap(u,v);
	add(1,1,n,dfn[v]+1,dfn[u],1);
}
inline int lca_mx(int u,int v){
	int res=0;
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])
			std::swap(u,v);
		res=std::max(res,mx(1,1,n,dfn[top[u]],dfn[u]));
		u=fa[top[u]];
	}
	if(dep[u]<dep[v])
		std::swap(u,v);
	res=std::max(res,mx(1,1,n,dfn[v]+1,dfn[u]));
	return res;
}

int ans[M];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,x;
		scanf("%d%d%d",&u,&v,&x);
		int fu=fnd(u),fv=fnd(v);
		if(fu==fv){
			a.push_back(mp(mp(u,v),mp(x,i)));
		}
		else{
			f[fu]=fv;
			addedge(u,v,x);
			addedge(v,u,x);
			ans[i]=1;
		}
	}
	for(int i=1;i<=n;i++)
		if(!dep[i])
			dfs1(i);
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			dfs2(i);
	for(auto [_,__]:a){
		auto [u,v]=_;
		auto [x,i]=__;
		int y=s[u]^s[v];
		if(!(x^y)||lca_mx(u,v))
			continue;
		lca_add(u,v);
		ans[i]=1;
	}
	for(int i=1;i<=m;i++)
		puts(ans[i]?"YES":"NO");
}