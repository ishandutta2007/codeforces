#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<int> g[20];
int dp[1000000][20];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=0;i<n;i++){
		dp[1<<i][i]=1;
	}
	for(int i=1;i<(1<<n);i++){
		int side1=log2(i&-i);
//		cout<<i<<" "<<side1<<endl;
		for(int side2=0;side2<n;side2++){
			if((i&1<<side2)&&(side2!=side1)){
				for(int v=0;v<g[side2].size();v++){
					dp[i][side2]+=dp[i^1<<side2][g[side2][v]];
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<(1<<n);i++){
		if(__builtin_popcount(i)<=2)	continue;
		int side1=log2(i&-i);
		for(int u=0;u<g[side1].size();u++){
			ans+=dp[i][g[side1][u]];
		}
	}
	cout<<ans/2<<endl;
}