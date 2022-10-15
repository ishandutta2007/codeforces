#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5;

int n, ai, dp[mxN+1], mi=1, prv[mxN+1], ans[mxN];
unordered_map<int, int> occ;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> ai;
		prv[i]=occ[(ai-1)^6969];
		dp[i]=dp[prv[i]]+1;
		occ[ai^6969]=i;
		if(dp[i]>dp[mi])
			mi=i;
	}
	cout << dp[mi] << "\n";
	for(int i=mi, i2=0; i; i=prv[i])
		ans[i2++]=i;
	for(int i=dp[mi]-1; i>=0; --i)
		cout << ans[i] << " ";
}