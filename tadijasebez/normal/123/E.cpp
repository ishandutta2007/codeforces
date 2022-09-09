#include <bits/stdc++.h>
using namespace std;
#define ldb double
#define ll long long
#define pb push_back
const int N=100050;
ll dp[N],dw[N],up[N];
int sz[N],sum_y[N],x[N],y[N],n,X,Y;
vector<int> E[N];
void DFS(int u,int p){
	sz[u]=1;
	sum_y[u]=y[u];
	for(int v:E[u])if(v!=p){
		DFS(v,u);
		sz[u]+=sz[v];
		sum_y[u]+=sum_y[v];
	}
	for(int v:E[u])if(v!=p){
		dw[u]+=dw[v]+(ll)(sz[u]-sz[v])*sum_y[v];
	}
}
ll Solve(int u,int p){
	ll all=p!=0?up[u]-(ll)(n-sz[u])*(Y-sum_y[u]):0;
	for(int v:E[u])if(v!=p){
		all+=dw[v]-(ll)sz[v]*sum_y[v];
	}
	dp[u]=all+(ll)n*(Y-y[u]);
	ll ans=(ll)dp[u]*x[u];
	for(int v:E[u])if(v!=p){
		up[v]=all-(dw[v]-(ll)sz[v]*sum_y[v]);
		up[v]+=(ll)(n-sz[v])*(Y-sum_y[v]-y[u]);
		ans+=Solve(v,u);
	}
	return ans;
}
int main(){
	scanf("%i",&n);
	for(int i=1,u,v;i<n;i++)scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	int sum_x=0,sum_y=0;
	for(int i=1;i<=n;i++)scanf("%i %i",&x[i],&y[i]),X+=x[i],Y+=y[i];
	DFS(1,0);
	printf("%.12f\n",(ldb)Solve(1,0)/X/Y);
	return 0;
}