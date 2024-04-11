#include<bits/stdc++.h>
#define N 200005

int n,m;
std::vector<std::pair<int,int>> q;

std::vector<int> E[N];

#define W 20
int deg[N],dep[N],f[N][W],dfn[N],_dfn,s[N];
inline void Dfs(int u,int fa){
	if(fa)
		E[u].erase(std::find(E[u].begin(),E[u].end(),fa));
	deg[u]=E[u].size();
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<W;i++)
		f[u][i]=f[f[u][i-1]][i-1];
	dfn[u]=++_dfn;
	s[u]=s[fa]+deg[u];
	for(auto v:E[u])
		Dfs(v,u);
}
inline int lca(int u,int v){
	if(dep[u]<dep[v])
		std::swap(u,v);
	for(int i=W-1;~i;i--)
		if(dep[f[u][i]]>dep[v])
			u=f[u][i];
	if(dep[u]>dep[v])
		u=f[u][0];
	for(int i=W-1;~i;i--)
		if(f[u][i]!=f[v][i])
			u=f[u][i],v=f[v][i];
	return u==v?u:f[u][0];
}

std::map<std::pair<int,int>,int> ans;
std::vector<int> T[N];
int F[N];
inline void dfs(int u,int k){
	int tmp=deg[u];
	for(auto v:T[u]){
		dfs(v,k);
		tmp+=std::max(1ll,F[v]+s[f[v][0]]-s[u]-1ll*(k+1)*(dep[f[v][0]]-dep[u]))-1;
	}
	ans[{u,k}]=tmp;
	F[u]=std::max(1,tmp-k);
}
inline void sol(int k,std::vector<int> &V){
	V.push_back(1);
	auto cmp=[&](int i,int j){
		return dfn[i]<dfn[j];
	};
	std::sort(V.begin(),V.end(),cmp);
	auto U=V;
	for(int i=1;i<(int)U.size();i++)
		V.push_back(lca(U[i],U[i-1]));
	std::sort(V.begin(),V.end(),cmp),V.erase(std::unique(V.begin(),V.end()),V.end());
	for(int i=1;i<(int)V.size();i++)
		T[lca(V[i],V[i-1])].push_back(V[i]);
	dfs(1,k);
	for(auto u:V)
		T[u].clear();
}

std::vector<int> V[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		E[u].push_back(v),E[v].push_back(u);
	}
	Dfs(1,0);
	for(int u=1;u<=n;u++)
		for(int i=0;i<deg[u];i++)
			V[i].push_back(u);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int u,k;
		scanf("%d%d",&u,&k);
		V[k].push_back(u);
		q.emplace_back(u,k);
	}
	for(int i=0;i<=2e5;i++)
		sol(i,V[i]);
	for(auto x:q)
		printf("%d\n",ans[x]);
}