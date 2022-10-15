#include <bits/stdc++.h>
using namespace std;

#define ld long double

const int mxN=100;
int tests, n;
ld c, t, dp[2][mxN+1][mxN*10+1];
array<int, 2> a[mxN];

void solve() {
	cin >> n >> c >> t;
	for(int i=0; i<n; ++i)
		cin >> a[i][0] >> a[i][1];
	sort(a, a+n);
	for(int j=0; j<=n; ++j)
		for(int k=0; k<=10*n; ++k)
			dp[0][j][k]=1e15;
	dp[0][0][0]=0;
	for(int i=1; i<=n; ++i) {
		for(int j=0; j<=n; ++j) {
			for(int k=0; k<=10*n; ++k) {
				dp[i&1][j][k]=dp[i&1^1][j][k];
				if(j&&k>=a[i-1][1])
					dp[i&1][j][k]=min((dp[i&1^1][j-1][k-a[i-1][1]]+a[i-1][0])/0.9, dp[i&1][j][k]);
			}
		}
	}
	int ans=0;
	for(int i=1; i<=n; ++i) {
		ld b=t-i*10+1/c;
		if(b<0)
			break;
		b/=2;
		b*=b;
		b*=c;
		for(int k=0; k<=10*n; ++k) {
			if(c*dp[n&1][i][k]<1) {
				if(dp[n&1][i][k]+i*10<=t)
					ans=max(k, ans);
			} else if(dp[n&1][i][k]<=b)
				ans=max(k, ans);
		}
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> tests;
	while(tests--)
		solve();
}