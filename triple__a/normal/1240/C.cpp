#include<bits/stdc++.h>
using namespace std;

const int maxn=500007;

int q,n,k;
long long ans=0;
long long dp[maxn][2];
vector<pair<int,int> > e[maxn];
bool vis[maxn];

void dfs(int u){
	vis[u]=1;
	dp[u][0]=dp[u][1]=0;
	vector<long long> vec;
	long long sum=0;
	vec.clear();
	for (auto c:e[u]){
		int v=c.first,w=c.second;
		if (!vis[v]){
			dfs(v);
			sum+=dp[v][1];
			vec.push_back(max(0ll,dp[v][0]+w-dp[v][1]));
		}
	}
	sort(vec.begin(),vec.end());
	int t=vec.size();
	for (int i=1;i<k;++i){
		if (i>t) break;
		sum+=vec[t-i];
	}
	dp[u][0]=sum;
	if (k>t){
		dp[u][1]=sum;
	}
	else{
		dp[u][1]=sum+vec[t-k];
	}
//	cout<<u<<" "<<sum<<" "<<dp[u][0]<<" "<<dp[u][1]<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>q;
	while(q--){
		cin>>n>>k;
		for (int i=1;i<=n;++i){
			vis[i]=0;
			e[i].clear();
		}
		for (int i=1;i<n;++i){
			int u,v,w;
			cin>>u>>v>>w;
			e[u].push_back({v,w});
			e[v].push_back({u,w});
		}
		dfs(1);
		cout<<dp[1][1]<<endl;
	}
	return 0;
}