#include<bits/stdc++.h>
using namespace std;
int sum[1005],dp[1005][2];;
int main()
{
	ios::sync_with_stdio(false);
	int n,m,x,y;
	char c;
	cin>>n>>m>>x>>y;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>c;
			if(c=='#') 
				sum[j+1]++;
		}
	}
	for(int i=1;i<=m;i++)
		sum[i]+=sum[i-1];
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	dp[0][1]=0;
	for(int i=0;i<m;i++)
	{
		for(int j=x;j<=y;j++)
		{
			if(i+j<=m)
			{
				dp[i+j][0]=min(dp[i+j][0],dp[i][1]+n*j-sum[i+j]+sum[i]);
				dp[i+j][1]=min(dp[i+j][1],dp[i][0]+sum[i+j]-sum[i]);
			}
		}
	}
	cout<<min(dp[m][0],dp[m][1])<<endl;
	return 0;
}