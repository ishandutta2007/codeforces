#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e3;
int n, h, l, r, a[mxN], dp[mxN+1][mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> h >> l >> r;
	memset(dp, 0xc0, sizeof(dp));
	dp[0][0]=0;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		for(int j=0; j<h; ++j) {
			int nj=(j+a[i]-1)%h;
			dp[i+1][nj]=max(dp[i][j]+(l<=nj&&nj<=r), dp[i+1][nj]);
			nj=(j+a[i])%h;
			dp[i+1][nj]=max(dp[i][j]+(l<=nj&&nj<=r), dp[i+1][nj]);
		}
	}
	int ans=0;
	for(int i=0; i<h; ++i)
		ans=max(dp[n][i], ans);
	cout << ans;
}