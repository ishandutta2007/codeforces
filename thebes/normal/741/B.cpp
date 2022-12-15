#include <bits/stdc++.h>
using namespace std;

const int MN = 1e3+3;
int dp[MN], arr[MN], N, M, W, w[MN], b[MN], i, vis[MN];
vector<int> adj[MN];

void upd(pair<int,int> p){
	for(int i=W;i>=0;i--){
		if(i>=p.first) arr[i]=max(arr[i],dp[i-p.first]+p.second);
	}
}

pair<int,int> dfs(int n){
	pair<int,int> r(w[n],b[n]);
	upd(r); vis[n] = 1;
	for(auto v : adj[n]){
		if(vis[v]) continue;
		pair<int,int> a=dfs(v);
		r.first+=a.first;
		r.second+=a.second;
	}
	return r;
}

int main(){
	for(scanf("%d%d%d",&N,&M,&W),i=1;i<=N;i++)
		scanf("%d",&w[i]);
	for(i=1;i<=N;i++)
		scanf("%d",&b[i]);
	for(i=0;i<M;i++){
		int x, y; scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(i=1;i<=N;i++){
		if(vis[i]) continue;
		pair<int,int> s=dfs(i);
		upd(s);
		for(int j=W;j>=0;j--)
			dp[j]=max(dp[j],arr[j]);
		memset(arr, 0, sizeof(arr));
	}
	printf("%d\n",dp[W]);
	return 0;
}