#include <iostream>
#include <algorithm>
using namespace std;
inline int d(int x,int y)
{
	return max(x,y)-min(x,y);
}
int a[295],dp[205][505];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		sort(a+1,a+n+1);
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=400;j++)
				dp[i][j]=1e9;
		}
		dp[0][0]=0;
		int ans=1e9;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=400;j++)
			{
				for(int k=j+1;k<=400;k++)
				{
					dp[i][k]=min(dp[i][k],dp[i-1][j]+d(k,a[i]));
				}
			}
			if(i==n)for(int j=1;j<=400;j++)
			ans=min(ans,dp[i][j]);
		}
		cout << ans << "\n";
	}
	return 0;
}