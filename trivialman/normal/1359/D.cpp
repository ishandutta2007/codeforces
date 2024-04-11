#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const int P = 998244353;
const int N = 1e5+5;
const double PI = acos(-1);
mt19937 rng(time(0));

int n, x, dp[N][35], ans = 0;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&x);
		rep(j,max(1,x+1),30) dp[i][j] = dp[i-1][j] + x;
		rep(j,0,x) dp[i][x] = max(dp[i-1][j] + x, dp[i][x]);
		dp[i][0] = 0;
		rep(j,0,30) ans = max(ans, dp[i][j] - j);
	}
	cout<<ans<<endl;
	return 0;
}