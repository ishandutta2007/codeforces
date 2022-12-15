#include <bits/stdc++.h>
using namespace std;

const int MN = 6e5+5;
int vis[MN][2], N, M, i, x, y, w=1, sz=1, cmp[MN], val[MN], st[MN];
vector<pair<int,int>> adj[MN], cadj[MN]; stack<int> s;

void dfs(int n, int p){
	vis[n][0]=vis[n][1]=++w;
	st[n]=1; s.push(n);
	for(auto t : adj[n]){
		int v = t.first; if(v==p) continue;
		if(!vis[v][0])dfs(v,n),vis[n][0]=min(vis[v][0],vis[n][0]);
		else if(st[v]) vis[n][0]=min(vis[v][1],vis[n][0]);
	}
	if(vis[n][0]==vis[n][1]){
		while(s.size()&&s.top()!=n)
			cmp[s.top()]=sz,st[s.top()]=0,s.pop();
		cmp[s.top()]=sz,st[s.top()]=0,s.pop(); sz++;
	}
}

void dfs1(int n, int flag){
	flag = max(flag, val[n]);
	if(n==y) printf("%s\n",(flag)?"YES":"NO");
	vis[n][0] = 1;
	for(auto v : cadj[n])
		if(!vis[v.first][0])
			dfs1(v.first,max(flag,v.second));
}

int main(){
	for(scanf("%d%d",&N,&M),i=1;i<=M;i++){
		scanf("%d%d%d",&x,&y,&w);
		adj[x].push_back({y,w});
		adj[y].push_back({x,w});
	}
	for(i=1;i<=N;i++)
		if(!vis[i][0]) dfs(i,-1);
	for(i=1;i<=N;i++){
		for(auto v : adj[i]){
			if(cmp[i]==cmp[v.first]&&v.second) val[cmp[i]]=1;
			else cadj[cmp[i]].push_back({cmp[v.first],v.second});
		}
	}
	memset(vis,0,sizeof(vis));
	scanf("%d%d",&x,&y);
	x=cmp[x]; y=cmp[y]; dfs1(x,0);
	return 0;
}