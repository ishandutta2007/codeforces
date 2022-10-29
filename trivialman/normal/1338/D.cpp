#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define PB push_back
const int N = 1e5+5;

vector<int> g[N];
int n, x, y, ans = 0;
int dp[N][2];

void dfs(int x, int fa){
	int adj = g[x].size(), i0, i1, tmp;
	
	if (adj==1 && fa != 0)
		dp[x][0] = dp[x][1] = 1;
	else{
		for(auto u:g[x]) if(u != fa) {
			dfs(u, x);
			tmp = max(dp[u][0] + adj - 2, dp[u][1] + adj - 1);
			if (tmp > dp[x][0]) dp[x][0] = tmp, i0 = u;
			if (dp[u][0] > dp[x][1]) dp[x][1] = dp[u][0], i1 = u;
		}
	}
	
	ans = max(ans, max(dp[x][0], dp[x][1]));
	for(auto u:g[x]) if(u != fa) {
		if (u != i0) ans = max(ans, dp[x][0] + max(dp[u][0]-2, dp[u][1]-1));
		if (u != i1) ans = max(ans, dp[x][1] + dp[u][0] - 1);
	}
}

int main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		scanf("%d%d",&x,&y);
		g[x].PB(y), g[y].PB(x);
	}
	
	memset(dp,0,sizeof dp);
	dfs(1, 0);
	printf("%d\n", ans);
	
	return 0;
}