#include<bits/stdc++.h>
#define N 100005

int n,m;

std::vector<std::pair<int,int>> ans;

std::vector<int> E[N];

std::vector<int> T[N];
int fa[N],dfn[N],_dfn,low[N];
inline void Dfs(int u){
	low[u]=dfn[u]=++_dfn;
	for(auto v:E[u])
		if(!dfn[v]){
			fa[v]=u;
			Dfs(v);
			low[u]=std::min(low[u],low[v]);
			if(low[v]>dfn[u])
				T[u].push_back(v),T[v].push_back(u);
		}
		else if(v!=fa[u])
			low[u]=std::min(low[u],dfn[v]);
}

int f[N],g[N];
inline void dfs(int u,int Fa){
	if(Fa)
		T[u].erase(std::find(T[u].begin(),T[u].end(),Fa));
	for(auto v:T[u])
		dfs(v,u);
	if(!T[u].size())
		return f[u]=1,g[u]=u,void();
	std::sort(T[u].begin(),T[u].end(),[&](int i,int j){
		return f[i]<f[j];
	});
	while(T[u].size()){
		int v=T[u].back();
		T[u].pop_back();
		if(!f[u]&&Fa)
			f[u]=f[v]+1,g[u]=g[v];
		else if(T[u].size()){
			ans.emplace_back(g[v],g[T[u].back()]);
			T[u].pop_back();
		}
		else if(f[v]>1){
			if(f[u]){
				ans.emplace_back(g[u],g[v]);
				f[u]=1,g[u]=u;
			}
			else
				ans.emplace_back(u,g[v]);
		}
	}
}

int main(){
	while(scanf("%d%d",&n,&m)){
		if(!n&&!m)
			break;
		ans.clear();
		for(int i=1;i<=n;i++)
			E[i].clear();
		for(int i=1;i<=m;i++){
			int k,u;
			scanf("%d%d",&k,&u);
			for(k--;k;k--){
				int v;
				scanf("%d",&v);
				E[u].emplace_back(v),E[v].emplace_back(u);
				u=v;
			}
		}
		_dfn=0;
		for(int i=1;i<=n;i++)
			dfn[i]=0;
		Dfs(1);
		for(int i=1;i<=n;i++)
			f[i]=0;
		for(int i=1;i<=n;i++)
			if(!f[i])
				dfs(i,0);
		printf("%d\n",(int)ans.size());
		for(auto [u,v]:ans)
			printf("%d %d\n",u,v);
	}
}