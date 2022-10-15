#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, mxP=7;
int n, p, k, a[mxN], s[mxN][mxP], ib[mxN];
ll dp[mxN+1][1<<mxP];
ar<int, 2> b[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p >> k;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		b[i]={a[i], i};
	}
	sort(b, b+n, greater<ar<int, 2>>());
	for(int i=0; i<n; ++i) {
		for(int j=0; j<p; ++j) {
			cin >> s[i][j];
		}
		ib[b[i][1]]=i;
	}

	memset(dp, 0xc0, sizeof(dp));
	dp[0][0]=0;
	for(int i=0; i<n; ++i) {
		for(int j=(1<<p)-1; ~j; --j) {
			int na=i-__builtin_popcount(j);
			ll d=dp[i][j];
			if(na<k) {
				d+=b[i][0];
			}
			dp[i+1][j]=max(dp[i+1][j], d);
			for(int l=0; l<p; ++l) {
				if(j>>l&1)
					continue;
				dp[i+1][j|1<<l]=max(dp[i+1][j|1<<l], dp[i][j]+s[b[i][1]][l]);
			}
		}
	}
	//cout << dp[2][2] << endl;
	cout << dp[n][(1<<p)-1];
}