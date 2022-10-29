#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2>
typedef long long LL;
const LL P = 1e9+7;
const LL INF = 1e18;
const int N = 2e5+5;
mt19937 rng(time(0));
 
int T, n, dp[10][10];
char s[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	cin>>T;
	while(T--){
		scanf("%s", s+1);
		n = strlen(s+1);
		memset(dp,0,sizeof dp);
		
		rep(i,1,n){
			int x = s[i] - '0';
			rep(y,0,9) dp[y][x] = dp[x][y] + 1;
		}
		
		int ans = 0;
		rep(i,0,9) rep(j,0,9) {
			int tmp = i==j ? dp[i][j] : dp[i][j]/2*2;
			ans = max(ans, tmp);
		}
		
		printf("%d\n", n-ans);
	}
	
	return 0;
}