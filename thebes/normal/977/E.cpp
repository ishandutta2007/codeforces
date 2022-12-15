#include <bits/stdc++.h>
using namespace std;

const int MN=2e5+5;
vector<int> adj[MN];
int vis[MN],n,m,i,x,y,cnt;

bool dfs(int n){
	vis[n] = 1;
	bool ret = (adj[n].size()==2);
	for(auto v : adj[n])
		if(!vis[v]&&!dfs(v)) ret=false;
	return ret;
}

int main(){
	for(scanf("%d%d",&n,&m);i<m;i++){
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(i=1;i<=n;i++)
		if(!vis[i]&&dfs(i)) cnt++;
	printf("%d\n",cnt);
	return 0;
}