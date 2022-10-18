#include<cstdio>
#include<algorithm>
#include<stack>
#include<set>
#define inf 0x3f3f3f3f
#define N 100005

int n,m,q,a[N];

namespace SegT{
	int t[N<<3];
	inline void chg(int p,int L,int R,int x,int d){
		if(L==R){
			t[p]=d;
			return;
		}
		int mid=(L+R)>>1;
		if(x<=mid)
			chg(p<<1,L,mid,x,d);
		else
			chg(p<<1|1,mid+1,R,x,d);
		t[p]=std::min(t[p<<1],t[p<<1|1]);
	}
	inline int mn(int p,int L,int R,int l,int r){
		if(L>r||R<l)
			return inf;
		if(l<=L&&R<=r)
			return t[p];
		int mid=(L+R)>>1;
		return std::min(mn(p<<1,L,mid,l,r),mn(p<<1|1,mid+1,R,l,r));
	}
}

namespace Tree{
	int tot;
	
	int hd[N<<1],_hd;
	struct edge{
		int v,nxt;
	}e[N<<1];
	inline void addedge(int u,int v){
		e[++_hd]=(edge){v,hd[u]};
		hd[u]=_hd;
	}
	
	std::multiset<int> s[N];
	
	int fa[N<<1],son[N<<1],dep[N<<1],sz[N<<1];
	inline void dfs1(int u){
		sz[u]=1;
		for(int i=hd[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(v==fa[u])
				continue;
			fa[v]=u;
			dep[v]=dep[u]+1;
			dfs1(v);
			sz[u]+=sz[v];
			if(sz[v]>sz[son[u]])
				son[u]=v;
		}
	}
	int dfn[N<<1],_dfn,top[N<<1];
	inline void dfs2(int u){
		dfn[u]=++_dfn;
		SegT::chg(1,1,tot,dfn[u],u<=n?a[u]:*s[u-n].begin());
		top[u]=u==son[fa[u]]?top[fa[u]]:u;
		if(son[u])
			dfs2(son[u]);
		for(int i=hd[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(v==fa[u]||v==son[u])
				continue;
			dfs2(v);
		}
	}
	
	inline int mn(int u,int v){
		int res=inf;
		while(top[u]!=top[v]){
			if(dep[top[u]]<dep[top[v]])
				std::swap(u,v);
			res=std::min(res,SegT::mn(1,1,tot,dfn[top[u]],dfn[u]));
			u=fa[top[u]];
		}
		if(dep[u]>dep[v])
			std::swap(u,v);
		res=std::min(res,SegT::mn(1,1,tot,dfn[u],dfn[v]));
		if(u>n)
			res=std::min(res,a[fa[u]]);
		return res;
	}
	inline void chg(int u,int d){
		if(fa[u])
			s[fa[u]-n].erase(s[fa[u]-n].find(a[u]));
		a[u]=d;
		if(fa[u])
			s[fa[u]-n].insert(a[u]);
		SegT::chg(1,1,tot,dfn[u],a[u]);
		if(fa[u])
			SegT::chg(1,1,tot,dfn[fa[u]],*s[fa[u]-n].begin());
	}
}

namespace Graph{
	int hd[N],_hd;
	struct edge{
		int v,nxt;
	}e[N<<1];
	inline void addedge(int u,int v){
		e[++_hd]=(edge){v,hd[u]};
		hd[u]=_hd;
	}
	
	int dfn[N],_dfn,low[N];
	std::stack<int> st;
	inline void dfs(int u,int fa){
		low[u]=dfn[u]=++_dfn;
		st.push(u);
		for(int i=hd[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(!dfn[v]){
				dfs(v,u);
				low[u]=std::min(low[u],low[v]);
				if(low[v]>=dfn[u]){
					Tree::tot++;
					Tree::addedge(u,Tree::tot);
					while(st.size()){
						int tmp=st.top();
						st.pop();
						Tree::addedge(Tree::tot,tmp);
						Tree::s[Tree::tot-n].insert(a[tmp]);
						if(tmp==v)
							break;
					}
				}
			}
			else if(v!=fa)
				low[u]=std::min(low[u],dfn[v]);
		}
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	Tree::tot=n;
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		Graph::addedge(u,v);
		Graph::addedge(v,u);
	}
	Graph::dfs(1,0);
	Tree::dfs1(1);
	Tree::dfs2(1);
	while(q--){
		char opt;
		int u,v;
		scanf("%s%d%d",&opt,&u,&v);
		if(opt=='A')
			printf("%d\n",Tree::mn(u,v));
		else
			Tree::chg(u,v);
	}
}