#include<bits/stdc++.h>
#define N 200005

int n,m;

std::multiset<std::pair<int,int>> s;

std::vector<int> E[N];
int fa[N],son[N],sz[N],dep[N];
inline void dfs1(int u){
	sz[u]=1;
	dep[u]=dep[fa[u]]+1;
	for(auto v:E[u])
		if(v!=fa[u]){
			fa[v]=u;
			dfs1(v);
			sz[u]+=sz[v];
			if(sz[v]>sz[son[u]])
				son[u]=v;
		}
}
int dfn[N],_dfn,id[N],top[N];
inline void dfs2(int u){
	dfn[u]=++_dfn;
	id[_dfn]=u;
	top[u]=u==son[fa[u]]?top[fa[u]]:u;
	if(son[u])
		dfs2(son[u]);
	for(auto v:E[u])
		if(v!=fa[u]&&v!=son[u])
			dfs2(v);
}

inline int lca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])
			std::swap(u,v);
		u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}
inline int la(int u,int k){
	while(u){
		if(dfn[u]-k>=dfn[top[u]])
			return id[dfn[u]-k];
		k-=dfn[u]-dfn[top[u]]+1;
		u=fa[top[u]];
	}
	return u?u:1;
}

int T[N];
inline int lb(int x){
	return x&-x;
}
inline void add(int x,int d){
	for(;x<=n;x+=lb(x))
		T[x]+=d;
}
inline int sum(int x){
	int res=0;
	for(;x;x-=lb(x))
		res+=T[x];
	return res;
}

inline int dis(int u,int v){
	if(!u||!v)
		return -1;
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}
struct node{
	int a[2],d;
	node(int u=0,int v=0){
		a[0]=u,a[1]=v;
		d=u&&v?dis(u,v):-1;
	}
}t[N<<2];
node operator + (node x,node y){
	static node d[6];
	for(int i=0;i<4;i++)
		d[i]=node(x.a[i>>1],y.a[i&1]);
	d[4]=x,d[5]=y;
	std::sort(d,d+6,[&](node i,node j){
		return i.d>j.d;
	});
	return d[0];
}
inline void ins(int p,int L,int R,int x){
	if(L==R){
		int u=id[L];
		t[p]=s.count({-dep[u],u})?node(u,u):node();
		return;
	}
	int mid=(L+R)>>1;
	if(x<=mid)
		ins(p<<1,L,mid,x);
	else
		ins(p<<1|1,mid+1,R,x);
	t[p]=t[p<<1]+t[p<<1|1];
}
inline node sum(int p,int L,int R,int l,int r){
	if(L>r||R<l)
		return node();
	if(l<=L&&R<=r)
		return t[p];
	int mid=(L+R)>>1;
	return sum(p<<1,L,mid,l,r)+sum(p<<1|1,mid+1,R,l,r);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		E[u].push_back(v),E[v].push_back(u);
	}
	dfs1(1),dfs2(1);
	while(m--){
		int op,u,v,d;
		scanf("%d",&op);
		if(op<=2){
			op=op==2?-1:1;
			scanf("%d%d",&u,&v);
			int w=lca(u,v);
			add(dfn[u],op),add(dfn[v],op),add(dfn[w],-op);
			if(op==1)
				s.insert({-dep[w],w});
			else
				s.erase(s.find({-dep[w],w}));
			ins(1,1,n,dfn[w]);
		}
		else{
			scanf("%d",&d);
			u=la(s.begin()->second,d),v=la(u,d);
			if(sum(dfn[v]+sz[v]-1)-sum(dfn[v]-1)!=s.size())
				puts("No");
			else{
				auto x=sum(1,1,n,dfn[v],dfn[v]+sz[v]-1);
				puts(std::max(dis(u,x.a[0]),dis(u,x.a[1]))<=d?"Yes":"No");
			}
		}
	}
}