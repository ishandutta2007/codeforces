#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int T, N, i, x, y, sz[MN], mx[MN];
vector<int> adj[MN], ct;

void dfs(int n,int p){
	sz[n] = 1; mx[n] = 0;
	for(auto v : adj[n]){
		if(v==p) continue;
		dfs(v, n);
		sz[n] += sz[v];
		mx[n] = max(mx[n], sz[v]);
	}
}

void dfs2(int n,int p){
	if(2*mx[n]<=N&&2*(N-sz[n])<=N)
		ct.push_back(n);
	for(auto v : adj[n]){
		if(v==p) continue;
		dfs2(v, n);
	}
}

pair<int,int> ree;

int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%d",&N);
		for(i=1;i<=N;i++)
			adj[i].clear();
		for(i=1;i<N;i++){
			scanf("%d%d",&x,&y);
			adj[x].push_back(y);
			adj[y].push_back(x);
			ree = {x, y};
		}
		ct.clear();
		dfs(1, 0);
		dfs2(1, 0);
		if(ct.size()==1){
			for(i=0;i<2;i++)
				printf("%d %d\n",ree.first,ree.second);
		}
		else{
			for(auto v : adj[ct[0]]){
				if(v!=ct[1]){
					printf("%d %d\n",ct[0],v);
					printf("%d %d\n",v,ct[1]);
					break;
				}
			}
		}
	}
	return 0;
}