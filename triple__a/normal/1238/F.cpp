#include<bits/stdc++.h>
using namespace std;

const int maxn=300007;

int dp[maxn][2],t,n;
bool vis[maxn];
vector<int> e[maxn];

void dfs(int u){
	vis[u]=1;
	int mx=1,sx=1;
	for (auto c:e[u]){
		if (vis[c]) continue;
		dfs(c);
		if (dp[c][0]>mx){
			sx=mx,mx=dp[c][0];
		}
		else{
			if (dp[c][0]>sx){
				sx=dp[c][0];
			}
		}
	}
	dp[u][0]=mx+e[u].size()-1;
	dp[u][1]=mx+sx+e[u].size()-1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=1;i<=n;++i){
			dp[i][0]=dp[i][1]=0;
			vis[i]=0;
			e[i].clear();
		}
		for (int i=1;i<n;++i){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1);
		int ans=0;
		for (int i=1;i<=n;++i){
			ans=max(dp[i][1],ans);
		}
		cout<<ans<<" ";
	}
	return 0;
}