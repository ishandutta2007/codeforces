#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2> 
typedef long long LL;
const int P = 1e9+7;
const int N = 5005;

int n, a, b, dp[N], lcs[N][N];
char s[N];

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>n>>a>>b;
	cin>>(s+1);
	
	dp[0] = 0;
	rep(i,1,n)dp[i] = 1e9; 
	rep(i,1,n){
		dp[i] = min(dp[i], dp[i-1]+a);
		rep(j,1,i-1){
			lcs[i][j] = s[i]==s[j] ? lcs[i-1][j-1]+1 : 0;
			if(i-lcs[i][j]>=j) dp[i] = min(dp[i], dp[i-lcs[i][j]]+b);
		}
	}
	cout<<dp[n]<<endl;
}