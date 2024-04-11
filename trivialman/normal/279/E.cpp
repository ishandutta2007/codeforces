#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 998244353;
const int INF = 0x3fffffff;
const int N = 1E6+5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, dp[N][2];
char s[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%s",s+1);
	n = strlen(s+1);
	s[n+1] = '0';
	dp[0][0] = 0, dp[0][1] = 1;
	rep(i,1,n+1){
		if(s[i]=='0'){
			dp[i][0] = dp[i-1][0];
			dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + 1;
		}else{
			dp[i][1] = dp[i-1][1];
			dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + 1;
		}
	}
	cout<<dp[n+1][0]<<endl;
	return 0;
}