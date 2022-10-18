#include<bits/stdc++.h>
#define N 300005

int n,m;

std::vector<int> E[N];

#define W 20
int fa[N][W],dep[N];
inline void dfs(int u){
	for(int i=1;i<W;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	dep[u]=dep[fa[u][0]]+1;
	for(auto v:E[u])
		dfs(v);
}
inline int jmp(int u,int v){
	for(int i=W-1;~i;i--)
		if(dep[fa[u][i]]>dep[v])
			u=fa[u][i];
	return u;
}

std::vector<int> A[N];
std::vector<std::pair<int,int>> B;

int f[N];
inline void dp(int u){
	for(auto v:E[u])
		dp(v),f[u]+=f[v];
	for(auto v:A[u])
		f[u]=std::max(f[u],f[v]+1);
}

int ans;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++){
		scanf("%d",&fa[i][0]);
		E[fa[i][0]].push_back(i);
	}
	dfs(1);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		if(dep[u]<dep[v])
			std::swap(u,v);
		int w=jmp(u,v);
		if(fa[w][0]==v){
			if(w==u)
				return puts("-1"),0;
			A[w].push_back(u);
		}
		else
			B.emplace_back(u,v);
	}
	dp(1);
	ans=f[1];
	for(auto [u,v]:B)
		ans=std::max(ans,f[u]+f[v]+1);
	printf("%d\n",ans);
}