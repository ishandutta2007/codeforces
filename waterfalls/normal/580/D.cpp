#include <bits/stdc++.h>

using namespace std;

int n,m,k;
int val[20];
int before[20][20];

long long dp[1048576][20];
long long solve(int mask, int last) {
	if (dp[mask][last]!=-1) return dp[mask][last];
	int prev = (mask^(1<<last));
	if (prev==0) return dp[mask][last] = val[last];
	for (int j=0;j<n;j++) if (prev&(1<<j)) {
		long long cur = solve(prev,j);
		cur+=val[last];
		cur+=before[j][last];
		dp[mask][last] = max(dp[mask][last],cur);
	}
	return dp[mask][last];
}

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<n;i++) scanf("%d",&val[i]);
	for (int i=0;i<k;i++) {
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		before[x-1][y-1]+=c;
	}
	memset(dp,-1,sizeof dp);
	long long ans = 0;
	for (int i=0;i<(1<<n);i++) if (__builtin_popcount(i)==m) {
		for (int j=0;j<n;j++) if (i&(1<<j)) ans = max(ans,solve(i,j));
	}
	printf("%lld\n",ans);

	return 0;
}