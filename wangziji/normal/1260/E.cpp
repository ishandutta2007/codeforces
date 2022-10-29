#include <iostream>
#define inf 5e18
#define int long long
using namespace std;
int dp[300005][20],a[300005],rk[300005],mn[300005][20],log2[300005];
signed main(int argc, char** argv) {
	int n,flag=0;
	cin >> n;
	for(int i=1;i<=300000;i++)
		log2[i]=log2[i/2]+1;
	for(int i=1;i<=n;i++)
	{
		rk[i]=i-1;
		cin >> a[i];
		if(a[i]==-1)
			flag=1,a[i]=inf;
		if(!flag)
			a[i]=0,++rk[i];
	}
	//for(int i=1;i<=n;i++)
	//	cout << rk[i] << " ";
//	cout << endl;
	for(int i=0;i<=n;i++)
	{
		for(int j=1;j<=19;j++)
			mn[i][j]=dp[i][j]=inf;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=19;j++)
		{
			if(((1<<j)-1)>rk[i])
			{
				//cout << rk[i] << " " << j << endl;
				continue;
			}
			dp[i][j]=mn[i-1][j-1]+a[i];
			mn[i][j]=min(dp[i][j],mn[i-1][j]);
		}
	}
	int ans=inf;
	for(int i=1;i<=n;i++)
		ans=min(ans,dp[i][(int)log2[n]-1]);
	cout << ans;
	return 0;
}
//dp[i][j]ij