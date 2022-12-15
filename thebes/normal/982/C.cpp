#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int dp[MN][2], N, i, x, y;
vector<int> adj[MN];

void solve(int n,int p){
	dp[n][0]=-1;
	for(auto v : adj[n]){
		if(v == p) continue;
		solve(v, n);
		int a=dp[n][0],b=dp[n][1];
		dp[n][0]=dp[n][1]=-1;
		if(dp[v][0]!=-1){
			if(a!=-1)dp[n][0]=max(dp[n][0],a+dp[v][0]+1);
			if(b!=-1)dp[n][1]=max(dp[n][1],b+dp[v][0]+1);
		}
		if(dp[v][1]!=-1){
			if(b!=-1)dp[n][0]=max(dp[n][0],b+dp[v][1]);
			if(a!=-1)dp[n][1]=max(dp[n][1],a+dp[v][1]);
		}
	}
}

int main(){
	for(scanf("%d",&N),i=1;i<N;i++){
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	solve(1,0);
	printf("%d\n",dp[1][0]);
	return 0;
}