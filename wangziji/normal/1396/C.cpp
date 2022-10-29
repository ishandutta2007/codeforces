#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int dp[1000005][2],w[1000005];
signed main(int argc, char** argv) {
	int n,x,y,z,d;
	cin >> n >> x >> y >> z >> d;
	for(int i=1;i<=n;i++)
		scanf("%lld",&w[i]),dp[i][0]=dp[i][1]=1e18;
	dp[1][0]=w[1]*x+z,dp[1][1]=min(w[1]*x+2*x,x+y)+d+d;
//	cout << dp[1][0] << " " << dp[1][1] << "\n";
	for(int i=2;i<=n;i++)
	{
		int w0=w[i]*x+z,w1=min(w[i]*x+2*x,x+y);
	//	cout << w0 << " " << w1 << "\n";
		dp[i][0]=w0+min(dp[i-1][0],dp[i-1][1]);
		dp[i][0]=min(dp[i][0],dp[i-1][1]+w1);
		if(i==n) dp[i][0]=min(dp[i][0],dp[i-1][1]+w0-d);
		dp[i][1]=dp[i-1][0]+w1+d+d;
	}
//	cout << dp[3][0] << " " << dp[3][1] << "\n";
	cout << min(dp[n][0],dp[n][1])+d*(n-1);
	return 0;
}