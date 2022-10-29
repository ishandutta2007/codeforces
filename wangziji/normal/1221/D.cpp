#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
struct node
{
	int a,b;
}a[300005];
int dp[300005][3];
signed main() {
	int T;
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i].a >> a[i].b;
		dp[1][0]=0,dp[1][1]=a[1].b,dp[1][2]=dp[1][1]*2;
		for(int i=2;i<=n;i++)
		{
			dp[i][0]=dp[i][1]=dp[i][2]=1e18;
			if(a[i].a!=a[i-1].a)
				dp[i][0]=min(dp[i][0],dp[i-1][0]);
			if(a[i].a!=a[i-1].a+1)
				dp[i][0]=min(dp[i][0],dp[i-1][1]);
			if(a[i].a!=a[i-1].a+2)
				dp[i][0]=min(dp[i][0],dp[i-1][2]);
			if(a[i].a+1!=a[i-1].a)
				dp[i][1]=min(dp[i][1],dp[i-1][0]+a[i].b);
			if(a[i].a+1!=a[i-1].a+1)
				dp[i][1]=min(dp[i][1],dp[i-1][1]+a[i].b);
			if(a[i].a+1!=a[i-1].a+2)
				dp[i][1]=min(dp[i][1],dp[i-1][2]+a[i].b);
			if(a[i].a+2!=a[i-1].a)
				dp[i][2]=min(dp[i][2],dp[i-1][0]+a[i].b+a[i].b);
			if(a[i].a+2!=a[i-1].a+1)
				dp[i][2]=min(dp[i][2],dp[i-1][1]+a[i].b+a[i].b);
			if(a[i].a+2!=a[i-1].a+2)
				dp[i][2]=min(dp[i][2],dp[i-1][2]+a[i].b+a[i].b);
		}
		cout << min(dp[n][0],min(dp[n][1],dp[n][2])) << "\n";
		for(int i=1;i<=n;i++)
			dp[i][0]=dp[i][1]=dp[i][2]=0;
	}
	return 0;
}