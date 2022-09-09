#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
const int N=100050;
vector<int> E[N];
int dp[N][2],go[N],par[N];
void DP(int u,int p){
	pii best={0,0};
	for(int v:E[u])if(v!=p){
		DP(v,u);par[v]=u;
		dp[u][0]+=max(dp[v][0],dp[v][1]);
		best=max(best,{dp[v][0]+1-max(dp[v][0],dp[v][1]),v});
	}
	dp[u][1]=dp[u][0]+best.first;
	go[u]=best.second;
}
bool up[N],dw[N];
void Rec(int u,int p){
	if(go[u]){
		dw[u]=1;
		up[go[u]]=1;
		for(int v:E[u])if(v!=p&&v!=go[u])Rec(v,u);
		for(int v:E[go[u]])if(v!=u)Rec(v,go[u]);
	}else for(int v:E[u])if(v!=p)Rec(v,u);
}
int ans[N];
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1,u,v;i<n;i++)scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DP(1,0);Rec(1,0);
	for(int i=1;i<=n;i++)if(up[i]){
		ans[i]=par[i];
		ans[par[i]]=i;
	}
	for(int i=1;i<=n;i++)if(!ans[i]){
		ans[i]=ans[par[i]];
		ans[par[i]]=i;
	}
	printf("%i\n",(n-2*dp[1][1])*2+(2*dp[1][1])*1);
	for(int i=1;i<=n;i++)printf("%i ",ans[i]);
	return 0;
}