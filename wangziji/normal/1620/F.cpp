#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005],dp[1000005][2];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++) cin >> a[i];
		a[0]=1e9,dp[0][0]=-1e9;
		for(int i=1;i<=n;i++) dp[i][0]=dp[i][1]=1e9;
		for(int i=1;i<=n;i++)
		{
			int x=-a[i-1],y=dp[i-1][0];
			if(a[i]>x) dp[i][1]=min(dp[i][1],y);
			if(a[i]>y) dp[i][1]=min(dp[i][1],x);
			if(-a[i]>x) dp[i][0]=min(dp[i][0],y);
			if(-a[i]>y) dp[i][0]=min(dp[i][0],x);
			x=a[i-1],y=dp[i-1][1];
			if(a[i]>x) dp[i][1]=min(dp[i][1],y);
			if(a[i]>y) dp[i][1]=min(dp[i][1],x);
			if(-a[i]>x) dp[i][0]=min(dp[i][0],y);
			if(-a[i]>y) dp[i][0]=min(dp[i][0],x);
		}
		if(dp[n][1]<=n||dp[n][0]<=n)
		{
			cout << "YES\n";
			int now=0;
			if(dp[n][1]<=n) now=1;
			for(int i=n;i>=1;i--)
			{
				if(now==1)
				{
					int x=-a[i-1],y=dp[i-1][0];
					if(a[i]>x&&dp[i][1]==y) now=0;
					if(a[i]>y&&dp[i][1]==x) now=0;
					x=a[i-1],y=dp[i-1][1];
					if(a[i]>x&&dp[i][1]==y) now=1;
					if(a[i]>y&&dp[i][1]==x) now=1;
				}
				else
				{
					int x=-a[i-1],y=dp[i-1][0];
					if(-a[i]>x&&dp[i][0]==y) now=0;
					if(-a[i]>y&&dp[i][0]==x) now=0;
					x=a[i-1],y=dp[i-1][1];
					if(-a[i]>x&&dp[i][0]==y) now=1;
					if(-a[i]>y&&dp[i][0]==x) now=1;
					a[i]=-a[i];
				}
			}
			for(int i=1;i<=n;i++)
				cout << a[i] << " ";
			cout << "\n";
		}
		else cout << "NO\n";
	}
	return 0;
}