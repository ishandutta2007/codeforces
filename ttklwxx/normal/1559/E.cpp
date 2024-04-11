#include<iostream>
#include<cstdio>
#define mod 998244353
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
int tl[100005],tr[200005];
int dp[51][100005];
int ans[100005];
int main()
{
	int n,m,l,r;
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		tl[i]=read();
		tr[i]=read();
	}
	for(int i=m;i>=1;i--)
	{
		dp[0][0]=1;
		for(int j=1;j<=m/i;j++)dp[0][j]=0;
		for(int j=1;j<=n;j++)
		{
			l=(tl[j]-1)/i+1;
			r=tr[j]/i;
			for(int k=0;k<=m/i;k++)dp[j][k]=0;
			if(l>r)continue;
			for(int k=0;k<=m/i;k++)
			{
				if(k+l>m/i)break;
				if(k+r+1<=m/i)dp[j][k+r+1]=(dp[j][k+r+1]+mod-dp[j-1][k])%mod;
				if(k+l>=0)dp[j][k+l]=(dp[j][k+l]+dp[j-1][k])%mod;
			}
			for(int k=1;k<=m/i;k++)dp[j][k]=(dp[j][k]+dp[j][k-1])%mod;
			//for(int k=1;k<=m/i;k++)printf("%d %d %d\n",j,k,dp[j][k]);
		}
		ans[i]=0;
		for(int k=1;k<=m/i;k++)ans[i]=(ans[i]+dp[n][k])%mod;
		for(int k=2*i;k<=m;k+=i)ans[i]=(ans[i]+mod-ans[k])%mod;
	}
	printf("%d\n",ans[1]);
	return 0;
}