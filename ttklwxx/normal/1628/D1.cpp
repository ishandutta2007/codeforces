#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
#define mod 1000000007
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
int dp[2005][2005];
signed main()
{
	int t,n,m,k,ans=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		k=read();
		dp[1][0]=0;
		dp[1][1]=k;
		for(int i=2;i<=n;i++)
		{
			dp[i][0]=0;
			dp[i][i]=1LL*i*k%mod;
			for(int j=1;j<=i-1;j++)
			{
				dp[i][j]=1LL*(dp[i-1][j-1]+dp[i-1][j])*(mod+1)/2%mod;
			}
		}
		printf("%lld\n",dp[n][m]);
	}
	return 0;
}