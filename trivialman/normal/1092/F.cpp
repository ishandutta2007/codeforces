#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define CL(a) memset(a,0,sizeof(a))

int n,x,y;
vector<int> g[N];
LL a[N],sum[N],cost[N],dp[N],ans=0;
bool v[N];

void dfs(int u){
	v[u] = true;
	sum[u] = a[u];
	for(auto x:g[u]){
		if(!v[x]){
			dfs(x);
			sum[u]+=sum[x];
			cost[u]+=cost[x]+sum[x];
		}
	}
}

void dfs2(int u,LL nowcost,LL nowsum){
	v[u] = true;
	ans = max(ans, nowcost+cost[u]);
	for(auto x:g[u]){
		if(!v[x]){
			dfs2(x,nowcost+(cost[u]-cost[x]-sum[x])+nowsum+sum[u]-sum[x],nowsum+sum[u]-sum[x]);
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n-1){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	CL(v);dfs(1);
	CL(v);dfs2(1,0,0);
	cout<<ans<<endl;
	return 0;
}