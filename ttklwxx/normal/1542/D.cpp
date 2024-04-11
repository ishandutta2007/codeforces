#include<iostream>
#include<cstdio>
#define mod 998244353
#define int long long
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
char fh[1005];
int sl[1005];
int dp[1005][1005];
int ksm(int n,int k)
{
	int ans=1;
	while(k>=1)
	{
		if(k&1)ans=1LL*ans*n%mod;
		k>>=1;
		n=1LL*n*n%mod;
	}
	return ans;
}
inline bool bi(int x,int y)
{
	if(x<=y&&sl[x]<=sl[y])return true;
	if(x>y&&sl[x]<sl[y])return true;
	return false;
}
signed main()
{
	int n,ans=0,tans=0;
	n=read();
	for(int i=1;i<=n;i++)
	{
		fh[i]=getchar();
		while(fh[i]!='-'&&fh[i]!='+')fh[i]=getchar();
		if(fh[i]=='+')sl[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		if(fh[i]=='-')continue;
		dp[0][0]=1;
		for(int j=1;j<=n;j++)
		{
			if(j==i)
			{
				dp[j][0]=0;
				for(int k=1;k<=j;k++)dp[j][k]=dp[j-1][k-1];
				continue;
			}
			if(fh[j]=='+'&&bi(j,i)==true)
			{
				dp[j][0]=dp[j-1][0];
				for(int k=1;k<=j;k++)dp[j][k]=(dp[j-1][k-1]+dp[j-1][k])%mod;
			}
			else if(fh[j]=='-')
			{
				dp[j][0]=(2*dp[j-1][0]+dp[j-1][1])%mod;
				for(int k=1;k<=j;k++)dp[j][k]=(dp[j-1][k+1]+dp[j-1][k])%mod;
			}
			else
			{
				for(int k=0;k<=j;k++)dp[j][k]=2*dp[j-1][k]%mod;
			}
			if(j>i)dp[j][0]=0;
		}
		tans=0;
		for(int j=1;j<=n;j++)tans=(tans+dp[n][j])%mod;
		ans=(ans+tans*sl[i])%mod;
	}
	printf("%lld\n",ans);
	return 0;
}