#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> g[3005];
int dfn[3005],idx=0,in[3005],fa[3005];
int depth[3005];
void find_loop(int x){
	dfn[x]=++idx;
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(y==fa[x])	continue;
		if(dfn[y]){
			if(dfn[y]<dfn[x])	continue;
			in[y]=1;
			for(;y!=x;y=fa[y]){
				in[fa[y]]=1;
			}
		}
		else{
			fa[y]=x;
			find_loop(y);
		}
	}
}
void dfs(int cur){
	for(int i=0;i<g[cur].size();i++){
		int to=g[cur][i];
		if(!in[to]&&depth[to]==0){
			depth[to]=depth[cur]+1;
			dfs(to);
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	find_loop(1);
	for(int i=1;i<=n;i++)
		if(in[i]){
			depth[i]=0;
			dfs(i);
		}
	for(int i=1;i<=n;i++){
		cout<<depth[i]<<" ";
	}
}