#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int ans=1<<30, n, i, x, y, dp[MN][2];
vector<pair<int,int>> adj[MN];
vector<int> vec;

void dfs1(int n, int p){
	for(auto v : adj[n]){
		if(v.first == p) continue;
		dfs1(v.first,n);
		dp[n][0]+=dp[v.first][0];
		dp[n][1]+=dp[v.first][1];
		dp[n][v.second]++;
	}
}

void dfs2(int n, int p, int r){
	if(dp[n][1]+r<ans) ans=dp[n][1]+r,vec.clear(), vec.push_back(n);
	else if(dp[n][1]+r==ans) vec.push_back(n);
	for(auto v : adj[n]){
		if(v.first == p) continue;
		int d = (v.second)? -1:1;
		dfs2(v.first,n,r+dp[n][1]-dp[v.first][1]+d);
	}
}

int main(){
	for(scanf("%d",&n),i=0;i<n-1;i++){
		scanf("%d%d",&x,&y);
		adj[x].push_back({y,0});
		adj[y].push_back({x,1});
	}
	dfs1(1,0); dfs2(1,0,0); 
	printf("%d\n",ans);
	sort(vec.begin(), vec.end());
	for(auto v : vec) printf("%d ",v);
	return 0;
}