#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2> 
#define vs vector<string>
typedef long long LL;
const LL P = 998244353;
const int N = 3005;
mt19937 rng(time(0));

char s[N], t[N];
int n, m, ans = 0, dp[N][N]; 

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>(s+1)>>(t+1);
	n = strlen(s+1), m = strlen(t+1);
	reverse(s+1,s+n+1);
	
	dp[0][0] = 1;
	rep(i,1,n){
		if (n-i+1>m) dp[i][0] = dp[i-1][0] + 1;
		else dp[i][0] = (s[i] == t[n-i+1]) * dp[i-1][0];
		//cout<<i<<" 0 "<<dp[i][0]<<endl;
		rep(j,1,i){
			bool f1 = (n-i+j+1>m) || s[i] == t[n-i+j+1], f2 = j > m || s[i] == t[j];
			dp[i][j] = (f1 * dp[i-1][j] + f2 * dp[i-1][j-1]) % P;
			//cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	
	rep(j,0,n) ans = (ans + dp[n][j]) % P;
	cout<<ans;
	return 0;
}