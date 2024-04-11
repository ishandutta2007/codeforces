#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const int N = 15, M = (1<<14) + 5;

int n;
char a[N][N];

vector<LL> dp[M][N];

int main() {
	cin>>n;
	rep(i,1,n) cin>>(a[i]+1);
	rep(i,1,n) rep(j,1,n) a[i][j] -= 48;
	
	rep(mask,0,(1<<n)-1) rep(j,1,n){
		if( !(mask>>j-1&1)  ) continue;
		int i = __builtin_popcount(mask);
		dp[mask][j].assign(1<<i-1, 0);
	}
	
	rep(i,1,n) dp[1<<i-1][i][0] = 1;
	
	rep(mask,1,(1<<n)-1) rep(j,1,n) rep(k,1,n){
		int x = 1<<j-1, y = 1<<k-1;
		if((mask&x) || !(mask&y)) continue;
		int i = __builtin_popcount(mask);
		rep(res,0,(1<<i-1)-1)
			dp[mask|x][j][res | (a[j][k]<<i-1)] += dp[mask][k][res];
	}
	
	int mask = (1<<n)-1;
	rep(res,0,(1<<n-1)-1){
		LL cnt = 0;
		rep(j,1,n) cnt += dp[mask][j][res];
		printf("%lld ",cnt);
	}
	return 0;
}