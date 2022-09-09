#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=2050;
int mx[N],mn[N],n;
vector<int> E[N];
int sz[N],ans;
vector<pair<int,int>> sgs[N];
void DFS(int u,int p){
	sz[u]=!!p;
	for(int v:E[u]){
		DFS(v,u);
		if(mx[v]!=0){
			sz[u]+=sz[v];
			mn[u]=min(mn[u],mn[v]);
			mx[u]=max(mx[u],mx[v]);
		}
	}
	if(mx[u]==0)ans++;
	else sgs[mx[u]].pb({mn[u],sz[u]});
}
void Tree(){
	int a;
	scanf("%i",&a);
	for(int i=1;i<=a;i++)mn[i]=1e9,mx[i]=0,E[i].clear();
	for(int i=2,p;i<=a;i++)scanf("%i",&p),E[p].pb(i);
	for(int i=1,x;i<=n;i++)scanf("%i",&x),mn[x]=mx[x]=i;
	DFS(1,0);
}
int dp[N];
int main(){
	scanf("%i",&n);
	Tree();
	Tree();
	dp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(auto s:sgs[i]){
			dp[i]=max(dp[i],dp[s.first-1]+s.second);
		}
	}
	printf("%i\n",dp[n]+ans);
	return 0;
}