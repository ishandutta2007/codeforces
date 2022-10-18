#include<cstdio>
#include<algorithm>
#include<set>
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define N 300005

int T;

int n;

int ans;

namespace T2{
	int hd[N],_hd;
	struct edge{
		int v,nxt;
	}e[N<<1];
	inline void addedge(int u,int v){
		e[++_hd]=(edge){v,hd[u]};
		hd[u]=_hd;
	}
	
	int fa[N],son[N],dep[N],sz[N];
	inline void dfs1(int u){
		dep[u]=dep[fa[u]]+1;
		sz[u]=1;
		for(int i=hd[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(v==fa[u])
				continue;
			fa[v]=u;
			dfs1(v);
			sz[u]+=sz[v];
			if(sz[v]>sz[son[u]])
				son[u]=v;
		}
	}
	int top[N],dfn[N],_dfn;
	inline void dfs2(int u){
		dfn[u]=++_dfn;
		top[u]=u==son[fa[u]]?top[fa[u]]:u;
		if(son[u])
			dfs2(son[u]);
		for(int i=hd[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(v==son[u]||v==fa[u])
				continue;
			dfs2(v);
		}
	}
	inline int lca(int u,int v){
		while(top[u]!=top[v]){
			if(dep[top[u]]<dep[top[v]])
				std::swap(u,v);
			u=fa[top[u]];
		}
		return dep[u]<dep[v]?u:v;
	}
	inline bool chka(int u,int v){
		return lca(u,v)==u;
	}
	
	std::set<pii> s;
	inline int ins(int u){
		auto it=s.insert(mp(dfn[u],u)).fir,L=it,R=it;
		R++;
		if(R!=s.end())
			if(chka(u,R->sec)){
				s.erase(it);
				return -1;
			}
		if(L==s.begin())
			return 0;
		L--;
		int v=L->sec;
		if(chka(v,u)){
			s.erase(L);
			return v;
		}
		else
			return 0;
	}
}

namespace T1{
	int hd[N],_hd;
	struct edge{
		int v,nxt;
	}e[N<<1];
	inline void addedge(int u,int v){
		e[++_hd]=(edge){v,hd[u]};
		hd[u]=_hd;
	}
	
	inline void dfs(int u,int fa){
//		auto t=T2::s;
		int flg=T2::ins(u);
		ans=std::max(ans,(int)T2::s.size());
		for(int i=hd[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(v==fa)
				continue;
			dfs(v,u);
		}
		if(flg>0)
			T2::s.insert(mp(T2::dfn[flg],flg));
		if(flg!=-1)
			T2::s.erase(mp(T2::dfn[u],u));
//		if(t!=T2::s)
//			puts("A");
	}
}

int main(){
	scanf("%d",&T);
	while(T--){
		for(int i=1;i<=n;i++)
			T1::hd[i]=T2::hd[i]=T2::son[i]=0;
		T1::_hd=T2::_hd=0;
		T2::_dfn=0;
		T2::s.clear();
		scanf("%d",&n);
		for(int i=2;i<=n;i++){
			int u;
			scanf("%d",&u);
			T1::addedge(u,i);
			T1::addedge(i,u);
		}
		for(int i=2;i<=n;i++){
			int u;
			scanf("%d",&u);
			T2::addedge(u,i);
			T2::addedge(i,u);
		}
		T2::dfs1(1);
		T2::dfs2(1);
		ans=0;
		T1::dfs(1,0);
		printf("%d\n",ans);
	}
}