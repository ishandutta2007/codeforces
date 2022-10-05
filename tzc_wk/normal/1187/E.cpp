#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,dp[200005],sz[200005],dp2[200005];
vector<int> g[200005];
void DP(int cur,int fa){
	dp[cur]=0;
	sz[cur]=1;
	for(int i=0;i<g[cur].size();i++){
		if(g[cur][i]==fa)	continue;
		DP(g[cur][i],cur);
		sz[cur]+=sz[g[cur][i]];
		dp[cur]+=dp[g[cur][i]];
	}
	dp[cur]+=sz[cur];
}
void DFS(int cur,int fa){
	for(int i=0;i<g[cur].size();i++){
		if(g[cur][i]==fa)	continue;
		dp2[g[cur][i]]=dp2[cur]+n-2*sz[g[cur][i]];
		DFS(g[cur][i],cur);
	}
}
signed main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	DP(1,0);
	dp2[1]=dp[1];
	DFS(1,0);
	cout<<*max_element(dp2+1,dp2+n+1)<<endl;
}