#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int N = 1e5+5;
mt19937 rng(time(0));

int T, n, k, z;
int a[N], dp[9][N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>T;
	
	while(T--){
		scanf("%d%d%d",&n,&k,&z);
		rep(i,1,n) scanf("%d",a+i);
		
		rep(i,0,z) dp[i][0] = 0;
		rep(i,1,k+1) dp[0][i] = dp[0][i-1] + a[i];
		int ans = dp[0][k+1];
		
		rep(i,1,z){
			rep(j,1,n){
				dp[i][j] = max(dp[i][j-1], dp[i-1][j+1]) + a[j];
				if(2*i+j==k+1) ans = max(ans, dp[i][j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}