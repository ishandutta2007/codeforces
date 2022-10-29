#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL P = 998244353;
const int N = 3e5+10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int n;
LL m,k,a[N],dp[N][10];
 
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n)scanf("%lld",a+i),a[i]=m*a[i]-k;
	dp[0][0] = 0;
	rep(j,1,m-1) dp[0][j] = -1e18;
	rep(i,0,n-1){
		rep(j,0,m-1){
			dp[i+1][(j+1)%m] = dp[i][j] + a[i+1];
		}
		dp[i+1][0] = max(dp[i+1][0], 0ll);
	}
	LL ans = 0;
	rep(j,0,m-1){
		LL tmp = 0;
		rep(i,1,n){
			tmp = max(tmp, dp[i][j]);
		}
		ans = max(ans, (tmp - (j?m-j:0) * k) / m);
	}
	printf("%lld\n",ans);
	return 0;
}