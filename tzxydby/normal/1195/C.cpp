#include<bits/stdc++.h>
using namespace std;
const int N=100005;
long long a[N][2],dp[N][2];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i][0];
	for(int i=1;i<=n;i++)
		cin>>a[i][1];
	dp[1][0]=a[1][0],dp[1][1]=a[1][1];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<2;j++)
		{
			dp[i+1][j^1]=max(dp[i+1][j^1],dp[i][j]+a[i+1][j^1]);
			dp[i+2][j^1]=max(dp[i+2][j^1],dp[i][j]+a[i+2][j^1]);	
		}
	}
	cout<<max(max(dp[n-1][0],dp[n-1][1]),max(dp[n][0],dp[n][1]))<<endl;
	return 0;
}