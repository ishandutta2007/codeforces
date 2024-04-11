#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100050;
vector<pair<int,int>> E[N];
int dep[N],par[N];
void DFS(int u,int p){
	par[u]=p;
	for(auto e:E[u])if(e.first!=p){
		dep[e.first]=dep[u]+e.second;
		DFS(e.first,u);
	}
}
bool was[N];
int DEP(int u,int p){
	int mx=0;
	for(auto e:E[u])if(e.first!=p && !was[e.first]){
		int t=DEP(e.first,u)+e.second;
		mx=max(mx,t);
	}
	return mx;
}
int dp[N],dpl[N],dpr[N];
int main(){
	int n,k;
	scanf("%i %i",&n,&k);
	for(int i=1,u,v,w;i<n;i++)scanf("%i %i %i",&u,&v,&w),E[u].pb({v,w}),E[v].pb({u,w});
	dep[1]=0;DFS(1,0);
	int cen=1,den=1;
	for(int i=1;i<=n;i++)if(dep[cen]<dep[i])cen=i;
	dep[cen]=0;DFS(cen,0);
	for(int i=1;i<=n;i++)if(dep[den]<dep[i])den=i;
	int diam=dep[den];
	for(int i=den;i;i=par[i])was[i]=1;
	vector<int> nodes;
	for(int i=den;i;i=par[i])dp[i]=DEP(i,0),nodes.pb(i);
	dpl[1]=dp[nodes.front()];
	for(int i=1;i<nodes.size();i++)dpl[i+1]=max(dp[nodes[i]],dpl[i]+dep[nodes[i-1]]-dep[nodes[i]]);
	dpr[nodes.size()]=dp[nodes.back()];
	for(int i=(int)nodes.size()-2;i>=0;i--)dpr[i+1]=max(dp[nodes[i]],dpr[i+2]+dep[nodes[i]]-dep[nodes[i+1]]);
	k=min(k,(int)nodes.size());
	int ans=1e9+7,mxd=0;
	for(int i=den;i;i=par[i])mxd=max(mxd,dp[i]);
	for(int i=k;i<=nodes.size();i++)ans=min(ans,max({dpl[i-k+1],dpr[i],mxd}));
	printf("%i\n",ans);
	return 0;
}