#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int D=18, M=998244353;
int k;
ll dp[D+1][2][2][1<<10], dp2[D+1][2][1<<10], d[D];

ll solve(ll a) {
	d[0]=a;
	for(int i=0; i<D; ++i) {
		d[i+1]=d[i]/10;
		d[i]%=10;
	}
	memset(dp, 0, sizeof(dp));
	memset(dp2, 0, sizeof(dp2));
	dp[D][0][0][0]=1;
	for(int i=D; i; --i) {
		for(int a=0; a<4; ++a) {
			for(int b=0; b<1<<10; ++b) {
				dp[i][a&1][a/2][b]%=M;
				dp2[i][a/2][b]%=M;
			}
		}
		if(d[i-1])
			dp[i-1][0][1][0]+=dp[i][0][0][0];
		else
			dp[i-1][0][0][0]+=dp[i][0][0][0];
		dp[i-1][0][1][0]+=dp[i][0][1][0];
		for(int j=1; j<d[i-1]; ++j) {
			dp[i-1][1][1][1<<j]+=dp[i][0][0][0];
			dp2[i-1][1][1<<j]+=dp[i][0][0][0]*j;
		}
		if(d[i-1]) {
			dp[i-1][1][0][1<<d[i-1]]+=dp[i][0][0][0];
			dp2[i-1][0][1<<d[i-1]]+=dp[i][0][0][0]*d[i-1];
		}
		for(int j=1; j<10; ++j) {
			dp[i-1][1][1][1<<j]+=dp[i][0][1][0];
			dp2[i-1][1][1<<j]+=dp[i][0][1][0]*j;
		}
		for(int b=0; b<1<<10; ++b) {
			for(int j=0; j<d[i-1]; ++j) {
				dp[i-1][1][1][b|1<<j]+=dp[i][1][0][b];
				dp2[i-1][1][b|1<<j]+=dp2[i][0][b]*10+dp[i][1][0][b]*j;
			}
			dp[i-1][1][0][b|1<<d[i-1]]+=dp[i][1][0][b];
			dp2[i-1][0][b|1<<d[i-1]]+=dp2[i][0][b]*10+dp[i][1][0][b]*d[i-1];
			for(int j=0; j<10; ++j) {
				dp[i-1][1][1][b|1<<j]+=dp[i][1][1][b];
				dp2[i-1][1][b|1<<j]+=dp2[i][1][b]*10+dp[i][1][1][b]*j;
			}
		}
	}
	ll r=0;
	for(int i=0; i<1<<10; ++i)
		if(__builtin_popcount(i)<=k)
			r+=dp2[0][0][i]+dp2[0][1][i];
	return r%M;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll l, r;
	cin >> l >> r >> k;
	cout << (solve(r)-solve(l-1)+M)%M;
}