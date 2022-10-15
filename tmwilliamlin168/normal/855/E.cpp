#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mxR=1e18;

ll dp[11][61][1024], dig[61];

inline ll solve(int b, ll r) {
	int len=1, pm=0;
	ll ans=0;
	while(r>=b) {
		ans+=dp[b][len][0]-dp[b][len-1][1];
		dig[len++]=r%b;
		r/=b;
	}
	dig[len]=r;
	ans-=dp[b][len-1][1];
	for(; len; --len) {
		for(int i=0; i<dig[len]; ++i)
			ans+=dp[b][len-1][(1<<i)^pm];
		pm^=1<<dig[len];
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	for(int b=2; b<=10; ++b) {
		dp[b][0][0]=1;
		ll pow=1;
		for(int len=1; pow<=mxR; ++len, pow=mxR/pow<b?mxR+1:pow*b)
			for(int i=0; i<b; ++i)
				for(int j=0; j<1<<b; ++j)
					dp[b][len][j]+=dp[b][len-1][j^(1<<i)];
	}
	int q, b;
	ll l, r;
	cin >> q;
	while(q--) {
		cin >> b >> l >> r;
		cout << solve(b, r+1)-solve(b, l) << "\n";
	}
}