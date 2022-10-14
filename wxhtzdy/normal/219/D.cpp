#include <bits/stdc++.h>
using namespace std;
const int N=200050;
int sum[N];
vector<pair<int,int>> E[N];
void DFS(int u,int p){
	for(auto e:E[u])if(e.first!=p){
		sum[1]+=e.second;
		DFS(e.first,u);
	}
}
void DP(int u,int p){
	for(auto e:E[u])if(e.first!=p){
		sum[e.first]=sum[u]-e.second+1-e.second;
		DP(e.first,u);
	}
}
int main(){
	int n;scanf("%i",&n);
	for(int i=1;i<n;i++){
		int u,v;scanf("%i %i",&u,&v);
		E[u].push_back({v,0});
		E[v].push_back({u,1});
	}
	DFS(1,1);DP(1,1);
	int ans=1e9;
	for(int i=1;i<=n;i++)ans=min(ans,sum[i]);
	printf("%i\n",ans);
	for(int i=1;i<=n;i++)if(ans==sum[i])printf("%i ",i);
	return 0;
}