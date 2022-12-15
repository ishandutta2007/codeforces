#include <bits/stdc++.h>
using namespace std;

typedef long long ll; const ll MN = 100005;
ll vis[MN], N, M, c[MN], i, x, y, ans;
vector<ll> adj[MN];

ll dfs(ll u){
	ll ret = c[u]; vis[u]=1;
	for(ll v : adj[u]){
		if(!vis[v]) ret=min(ret,dfs(v));
	}
	return ret;
}

int main(){
	for(scanf("%lld%lld",&N,&M),i=1;i<=N;i++)
		scanf("%lld",&c[i]);
	for(i=0;i<M;i++){
		scanf("%lld%lld",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(i=1;i<=N;i++){
		if(!vis[i]) ans+=dfs(i);
	}
	printf("%lld\n",ans);
	getchar(); getchar();
}