#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const int P = 1e9+7;
const int INF = P;
const int N = 2e5+5;
const double PI = acos(-1);
mt19937 rng(time(0));

int T, n, a[N], b[N];
int dp[N][2][2];
char s[N];

int work(int x1, int x2){
	int res = INF;
	rep(i,0,1) rep(j,0,1) dp[2][i][j] = INF;
	dp[2][x1][x2] = (a[1]!=x1) + (a[2]!=x2);
	rep(i,3,n) {
		dp[i][0][0] = dp[i-1][1][0] + (a[i]!=0);
		dp[i][0][1] = min(dp[i-1][1][0], dp[i-1][0][0]) + (a[i]!=1);
		dp[i][1][0] = min(dp[i-1][0][1], dp[i-1][1][1]) + (a[i]!=0);
		dp[i][1][1] = dp[i-1][0][1] + (a[i]!=1);
	}
	
	rep(i,0,1) rep(j,0,1){
		if (i==j && j==x1 || j==x1 && x1==x2) continue;
		res = min(res, dp[n][i][j]);
		//cout<<i<<" "<<j<<" "<<dp[n][i][j]<<endl;
	}
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	cin>>T;
	while(T--){
		scanf("%d\n%s",&n,s+1);
		rep(i,1,n) a[i] = (s[i]=='L') ? 0 : 1;
		
		int ans = INF;
		rep(i,0,1) rep(j,0,1) ans = min(ans, work(i,j));
		printf("%d\n",ans);
	}
	
	return 0;
}