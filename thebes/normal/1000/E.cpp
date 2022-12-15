#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int MN = 3e5+5;
int vis[MN][2], N, M, S, i, x, y, cmp[MN], t, st[MN], vs[MN];
vector<int> adj[MN], cadj[MN];
stack<int> s; queue<int> q;

void dfs(int x,int p){
	vis[x][0] = vis[x][1] = t++; s.push(x); st[x] = 1;
	for(int i=0;i<(signed)adj[x].size();i++){
		if(adj[x][i]==p) continue;
		if(!vis[adj[x][i]][1]){dfs(adj[x][i],x); vis[x][0]=min(vis[x][0],vis[adj[x][i]][0]);}
		else if(st[adj[x][i]]) vis[x][0] = min(vis[x][0],vis[adj[x][i]][1]);
	}
	if(vis[x][0] == vis[x][1]){
		S++;
		while(s.size() && s.top() != x){
			cmp[s.top()] = S; st[s.top()] = 0; s.pop();
		}
		cmp[x] = S; st[x] = 0; s.pop();
	}
}

int main(){
	for(scanf("%d%d",&N,&M),i=1;i<=M;i++){
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(i=1;i<=N;i++){if(!vis[i][1])dfs(i,-1);}
	for(i=1;i<=N;i++){
		for(auto v : adj[i]){
			if(cmp[i]!=cmp[v])
				cadj[cmp[i]].push_back(cmp[v]);
		}
	}
	q.push(1); int last=0; vs[1]=1;
	while(q.size()){
		int cur=q.front(); q.pop();
		for(auto v : cadj[cur]){
			if(!vs[v]){
				vs[v] = 1;
				q.push(v);
			}
		}
		last = cur;
	}
	q.push(last);
	memset(vs,0,sizeof(vs));
	vs[last] = 1;
	while(q.size()){
		int cur=q.front(); q.pop();
		for(auto v : cadj[cur]){
			if(!vs[v]){
				vs[v] = vs[cur]+1;
				q.push(v);
			}
		}
		last = cur;
	}
	printf("%d\n",vs[last]-1);
	getchar(); getchar();
}