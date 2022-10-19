#include<iostream>
#include<cstdio>
#include<algorithm>
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
int c[1005][1005];
int dp[62][2005][2];
signed main()
{
	int n,l,r,z;
	n=read();
	l=read();
	r=read();
	z=read();
	c[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
	}
	dp[61][0][1]=1;
	for(int i=60;i>=0;i--)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=n;k++)
			{
				int now=j*2-k;
				if((z&(1LL<<i))&&(k%2==0))continue;
				if(((z&(1LL<<i))==0)&&(k%2==1))continue;
				if(r&(1LL<<i))
				{
					if(now+1>=0&&now+1<=n)dp[i][now+1][1]=(dp[i][now+1][1]+1LL*dp[i+1][j][1]*c[n][k]%mod)%mod;
					if(now>=0&&now<=n)dp[i][now][0]=(dp[i][now][0]+1LL*dp[i+1][j][1]*c[n][k]%mod)%mod;
				}
				else
				{
					if(now>=0&&now<=n)dp[i][now][1]=(dp[i][now][1]+1LL*dp[i+1][j][1]*c[n][k]%mod)%mod;
				}
				if(now>=0&&now<=n)dp[i][now][0]=(dp[i][now][0]+1LL*dp[i+1][j][0]*c[n][k]%mod)%mod;
				if(now+1>=0&&now+1<=n)dp[i][now+1][0]=(dp[i][now+1][0]+1LL*dp[i+1][j][0]*c[n][k]%mod)%mod;
			}
		}
		/*for(int j=0;j<=n;j++)
		{
			if(dp[i][j][1]!=0)printf("%lld %lld 1 %lld\n",i,j,dp[i][j][1]);
			if(dp[i][j][0]!=0)printf("%lld %lld 0 %lld\n",i,j,dp[i][j][0]);
		}*/
	}
	int ans=(dp[0][0][1]+dp[0][0][0])%mod;
	for(int i=0;i<=60;i++)
	{
		for(int j=0;j<=n;j++)
		{
			dp[i][j][0]=dp[i][j][1]=0;
		}
	}
	dp[61][0][1]=1;
	for(int i=60;i>=0;i--)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=n;k++)
			{
				int now=j*2-k;
				if((z&(1LL<<i))&&(k%2==0))continue;
				if(((z&(1LL<<i))==0)&&(k%2==1))continue;
				if((l-1)&(1LL<<i))
				{
					if(now+1>=0&&now+1<=n)dp[i][now+1][1]=(dp[i][now+1][1]+1LL*dp[i+1][j][1]*c[n][k]%mod)%mod;
					if(now>=0&&now<=n)dp[i][now][0]=(dp[i][now][0]+1LL*dp[i+1][j][1]*c[n][k]%mod)%mod;
				}
				else
				{
					if(now>=0&&now<=n)dp[i][now][1]=(dp[i][now][1]+1LL*dp[i+1][j][1]*c[n][k]%mod)%mod;
				}
				if(now>=0&&now<=n)dp[i][now][0]=(dp[i][now][0]+1LL*dp[i+1][j][0]*c[n][k]%mod)%mod;
				if(now+1>=0&&now+1<=n)dp[i][now+1][0]=(dp[i][now+1][0]+1LL*dp[i+1][j][0]*c[n][k]%mod)%mod;
			}
		}
		/*for(int j=0;j<=n;j++)
		{
			if(dp[i][j][1]!=0)printf("%lld %lld 1 %lld\n",i,j,dp[i][j][1]);
			if(dp[i][j][0]!=0)printf("%lld %lld 0 %lld\n",i,j,dp[i][j][0]);
		}*/
	}
	int ans2=(dp[0][0][0]+dp[0][0][1])%mod;
	printf("%lld\n",(ans+mod-ans2)%mod);
	return 0;
}