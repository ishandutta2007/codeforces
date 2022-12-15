#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 3e5+5;
int N, M, i, x, y, arr[MN], rt, sm, vis[MN], deg[MN], sub[MN];
vector<pii> adj[MN], tree[MN]; vi ans;

void dfs(int n){
	vis[n] = 1;
	for(auto v : adj[n]){
		if(!vis[v.F]){
			dfs(v.F);
			if(arr[v.F]!=-1&&(deg[v.F]^arr[v.F])){
				ans.pb(v.S);
				deg[n] ^= 1;
			}
		}
	}
}

void dfs2(int n){
	vis[n] = 1;
	for(auto v : adj[n]){
		if(!vis[v.F]){
			tree[n].pb(v);
			dfs2(v.F);
		}
	}
}

void dfs3(int n,int pid){
	sub[n] = arr[n];
	for(auto v : tree[n]){
		dfs3(v.F, v.S);
		sub[n] ^= sub[v.F];
	}
	if(sub[n]) ans.pb(pid);
}

int main(){
	scanf("%d%d",&N,&M);
	for(i=1;i<=N;i++){
		scanf("%d",&arr[i]);
	}
	for(i=1;i<=M;i++){
		scanf("%d%d",&x,&y);
		adj[x].pb({y,i});
		adj[y].pb({x,i});
	}
	for(i=1;i<=N;i++){
		scanf("%d",&arr[i]);
		if(arr[i]==-1&&!rt) rt = i;
		if(arr[i]!=-1) sm += arr[i];
	}
	if(!rt){
		if(sm&1) printf("-1\n");
		else{
			dfs2(1); dfs3(1,-1);
			printf("%d\n",ans.size());
			for(auto v : ans)
				printf("%d\n",v);
		}
	}
	else{
		dfs(rt);
		printf("%d\n",ans.size());
		for(auto v : ans)
			printf("%d\n",v);
	}
	return 0;
}