#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int> adj[200013];
int dp[200013][2];

void dfs(int x, int p=0) {
	int tot = 0;
	vector<int> diff;
	for (int i: adj[x]) if (i!=p) {
		dfs(i,x);
		diff.push_back(dp[i][1]-dp[i][0]);
		tot+=dp[i][0];
	}
	sort(diff.begin(),diff.end());
	dp[x][0] = dp[x][1] = 1e9;
	dp[x][1] = min(dp[x][1],tot+1);
	if (diff.size()>0) dp[x][1] = min(dp[x][1],tot+diff[0]);
	if (diff.size()>1) dp[x][0] = min(dp[x][0],tot+diff[0]+diff[1]-1);
	dp[x][0] = min(dp[x][0],dp[x][1]);
}

int main() {
	ll x,y;
	scanf("%d%lld%lld",&n,&x,&y);
	for (int i=1;i<n;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	if (x>=y) {
		bool found = 0;
		for (int i=1;i<=n;i++) if (adj[i].size()==n-1) found = 1;
		if (found) printf("%lld\n",y*(n-2)+x);
		else printf("%lld\n",y*(n-1));
	} else {
		dfs(1);
		printf("%lld\n",(dp[1][0]-1)*y+(n-dp[1][0])*x);
	}

	return 0;
}