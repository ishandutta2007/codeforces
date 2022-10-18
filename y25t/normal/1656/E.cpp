#include<bits/stdc++.h>
#define N 100005

int T;

int n;

std::vector<int> E[N];

int a[N];

int dep[N];
inline void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	a[u]=(dep[u]&1?1:-1)*E[u].size();
	for(auto v:E[u]) if(v!=fa)
		dfs(v,u);
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			E[u].push_back(v),E[v].push_back(u);
		}
		dfs(1,0);
		for(int i=1;i<=n;i++)
			printf("%d ",a[i]);
		puts("");
		for(int i=1;i<=n;i++)
			E[i].clear();
	}
}