#include<iostream>
#include<cstdio>
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
int sl[1000005];
int dp[1005][1005];
signed main()
{
	int t,n,k;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		for(int i=0;i<=n;i++)dp[i][1]=1;
		for(int j=2;j<=k;j++)
		{
			dp[0][j]=1;
			for(int i=1;i<=n;i++)
			{
				dp[i][j]=(dp[i-1][j]+dp[n-i][j-1])%mod;
			}
		}
		printf("%lld\n",dp[n][k]);
	} 
	return 0;
}