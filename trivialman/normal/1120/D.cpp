#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define PB push_back
#define CL(a,x) memset(a, x, sizeof(a))
typedef long long LL;
const int N = 2e5+5;

int n,x,y,a[N];
bool v[2][N], yes[N];
vector<int> g[N];
LL dp[N],dp1[N];

void dfs(int x,int fa){
	if(g[x].size()==1 && x!=1){
		dp1[x] = 0, dp[x] = a[x];
		return;
	}
	LL ma = 0;
	for(auto u:g[x]) if(u!=fa) {
		dfs(u,x);
		ma = max(ma, dp[u]-dp1[u]);
		dp[x] += dp[u];
	}
	dp1[x] = dp[x] - ma;
	dp[x] = min(dp[x], dp1[x] + a[x]);
}
void dfs2(int x,int fa,int typ){
	if(v[typ][x]) return;
	v[typ][x] = true;
	LL sum = 0, ma = 0, cnt;
	for(auto u:g[x]) if(u!=fa){
		sum += dp[u];
		if(dp[u]-dp1[u]>ma) ma = dp[u]-dp1[u], cnt=1;
		else if(dp[u]-dp1[u]==ma) cnt++;
	}
	if(typ==1){
		for(auto u:g[x]) if(u!=fa){
			if(dp[u]-dp1[u]!=ma) dfs2(u,x,0);
			else{
				dfs2(u,x,1);
				if(cnt>1) dfs2(u,x,0);
			}
		}
	}else{
		if(sum==dp[x]){
			for(auto u:g[x]) if(u!=fa) dfs2(u,x,0);
		}
		if(dp1[x]+a[x]==dp[x]){
			yes[x] = true;
			for(auto u:g[x]) if(u!=fa){
				if(dp[u]-dp1[u]!=ma) dfs2(u,x,0);
				else{
					dfs2(u,x,1);
					if(cnt>1) dfs2(u,x,0);
				}
			}
		}
	}
}

int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",a+i);
	rep(i,1,n-1){
		scanf("%d%d",&x,&y);
		g[x].PB(y), g[y].PB(x);
	}
	dfs(1,0);
	CL(v,0), CL(yes,false);
	dfs2(1,0,0);
	vector<int> ans;
	rep(i,1,n) if(yes[i]) ans.PB(i);
	printf("%lld %d\n",dp[1],ans.size());
	for(auto x:ans) printf("%d ",x);
	return 0;
}