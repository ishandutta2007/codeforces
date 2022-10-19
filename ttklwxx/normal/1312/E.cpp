#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int dp[505][505],het[505][505],a[505];
int main()
{
	int n,ans,r;
	n=read();
	ans=n;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)dp[i][i]=1,het[i][i]=a[i];
	for(int len=2;len<=n;len++)
	{
		for(int l=1;l<=n-len+1;l++)
		{
			r=l+len-1;
			dp[l][r]=1000000000;
			for(int k=l;k<=r;k++)
			{
				dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
				if(dp[l][k]==1&&dp[k+1][r]==1&&het[l][k]==het[k+1][r])
				{
					dp[l][r]=1;
					het[l][r]=het[l][k]+1;
				}
			}
		}
	}
	printf("%d\n",dp[1][n]);
	return 0;
}