#include <iostream>
using namespace std;
int dp[505][505],mx[505],cd[505],a[505];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,x;
		cin >> n >> x;
		mx[0]=x;
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			if(a[i]<a[i-1]) flag=0;
			mx[i]=mx[i-1],cd[i]=cd[i-1];
			if(a[i]>mx[i]) cd[i]=mx[i],mx[i]=a[i];
			else if(a[i]>cd[i]) cd[i]=a[i];
		}
		/*if(flag)
		{
			puts("0");
			continue;
		}*/
		for(int i=0;i<=n;i++)
			for(int j=0;j<=500;j++) dp[i][j]=1e9;
		dp[0][x]=0;
		int ans=1e9;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=500;j++)
			{
				if(j==mx[i-1]&&a[i]>=cd[i-1]) dp[i][j]=min(dp[i][j],dp[i-1][j]);
				else if(a[i]>=mx[i-1]) dp[i][j]=min(dp[i][j],dp[i-1][j]);
				if(a[i]>j&&j>=mx[i-1]) dp[i][a[i]]=min(dp[i][a[i]],dp[i-1][j]+1);
			}
		}
		for(int i=0;i<=500;i++) ans=min(ans,dp[n][i]);
		if(ans>5e8) ans=-1;
		cout << ans << "\n";
	}
	return 0;
}