#include<bits/stdc++.h>
#define ll long long
#define N 200005

int T;

int n,k;

ll a[N];

std::vector<int> E[N];

ll f[N],g[N];

inline void dfs(int u,int x){
	if(!E[u].size()){
		f[u]=1ll*x*a[u],g[u]=a[u];
		return;
	}
	f[u]=g[u]=0;
	for(auto v:E[u])
		a[v]+=a[u],dfs(v,x/(int)E[u].size()),f[u]+=f[v];
	std::sort(E[u].begin(),E[u].end(),[&](int i,int j){
		return g[i]>g[j];
	});
	for(int i=0;i<x%(int)E[u].size();i++)
		f[u]+=g[E[u][i]];
	g[u]=g[E[u][x%(int)E[u].size()]];
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			E[i].clear();
		for(int i=2;i<=n;i++){
			int x;
			scanf("%d",&x);
			E[x].emplace_back(i);
		}
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		dfs(1,k);
		printf("%lld\n",f[1]);
	}
}