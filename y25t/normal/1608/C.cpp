#include<bits/stdc++.h>
#define N 100005

int T;

int n,a[N],b[N];

std::vector<int> E[N];

int p[N];

std::stack<int> st;
bool vis[N];
int dfn[N],_dfn,low[N];
std::vector<int> V;
inline void dfs(int u){
	st.push(u),vis[u]=1;
	dfn[u]=low[u]=++_dfn;
	for(auto v:E[u])
		if(!dfn[v]){
			dfs(v);
			low[u]=std::min(low[u],low[v]);
		}
		else if(vis[v])
			low[u]=std::min(low[u],dfn[v]);
	if(dfn[u]==low[u]){
		V.clear();
		while(st.size()){
			int v=st.top();
			st.pop(),vis[v]=0;
			V.push_back(v);
			if(v==u)
				break;
		}
	}
}

int ans[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		for(int i=1;i<=n;i++)
			E[i].clear();
		std::iota(p+1,p+n+1,1);
		for(int o=0;o<2;o++){
			std::sort(p+1,p+n+1,[&](int x,int y){
				return a[x]>a[y];
			});
			for(int i=1;i<n;i++)
				E[p[i]].push_back(p[i+1]);
			std::swap(a,b);
		}
		for(int i=1;i<=n;i++)
			dfn[i]=0;
		_dfn=0;
		for(int i=1;i<=n;i++)
			if(!dfn[i])
				dfs(i);
		for(int i=1;i<=n;i++)
			ans[i]=0;
		for(auto i:V)
			ans[i]=1;
		for(int i=1;i<=n;i++)
			putchar('0'+ans[i]);
		puts("");
	}
}