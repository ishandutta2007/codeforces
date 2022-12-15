#include <bits/stdc++.h>
using namespace std;

const int MN=1e6+6;
int deg[MN], vis[MN], N, M, i, x, y, cnt, cmp, ans, wtf;
vector<int> adj[MN]; queue<int> idk;
void dfs(int n){
	vis[n]=1;idk.push(n);
	for(auto v : adj[n])
		if(!vis[v]) dfs(v);
}
int main(){
	for(scanf("%d%d",&N,&M),i=1;i<=M;i++){
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
		deg[x]++; deg[y]++;
	}
	for(i=1;i<=N;i++){
		if((!vis[i])&&(i==1||deg[i])){
			dfs(i); int lol=0;
			while(idk.size()){
				int v=idk.front(); idk.pop();
				if(deg[v]%2) lol++;
			}
			if(!lol) cnt+=2; 
		}
		if(deg[i]%2) cnt++;
	}
	memset(vis,0,sizeof(vis));
	dfs(1); int lol=0;
	while(idk.size()){
		int v=idk.front(); idk.pop();
		if(deg[v]%2) lol++;
	}
	if(!lol&&cnt==2) cnt=0;
	printf("%d\n",cnt/2);
	return 0;
}