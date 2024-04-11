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
int dp[2005][2005],het[2005][2005];
int cfd[2005],cfh[2005];
char a[2005];
char b[2005];
int cy[2005];
int jdz(int x)
{
	if(x<0)return -x;
	return x;
}
signed main()
{
	int t,n,r,ans=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",a+1);
		scanf("%s",b+1);
		for(int i=1;i<=n;i+=2)
		{
			if(a[i]!='?')a[i]='0'+'1'-a[i];
			if(b[i]!='?')b[i]='0'+'1'-b[i];
		}
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				dp[i][j]=het[i][j]=0;
			}
		}
		dp[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]=='0'||a[i]=='?')
			{
				for(int j=0;j<=n;j++)
				{
					dp[i][j]=dp[i-1][j];
					het[i][j]=het[i-1][j];
				}
			}
			if(a[i]=='0')continue;
			for(int j=0;j<=n+1;j++)
			{
				cfd[j]=cfh[j]=0;
			}
			r=n+1;
			for(int j=n;j>=0;j--)
			{
				if(b[j]=='0')continue;
				cfd[j+1]=(cfd[j+1]+dp[i-1][j])%mod;
				cfh[j+1]=(cfh[j+1]+het[i-1][j])%mod;
				cfd[r+1]=(cfd[r+1]+mod-dp[i-1][j])%mod;
				cfh[r+1]=(cfh[r+1]+mod-het[i-1][j])%mod;
				if(b[j]=='1')r=j;
			}
			for(int j=1;j<=n;j++)
			{
				if(j!=0)
				{
					cfd[j]=(cfd[j]+cfd[j-1])%mod;
					cfh[j]=(cfh[j]+cfh[j-1])%mod;
				}
				if(b[j]=='0')continue;
				dp[i][j]=(dp[i][j]+cfd[j])%mod;
				het[i][j]=(het[i][j]+cfh[j]+1LL*cfd[j]*jdz(i-j)%mod)%mod;
			}
			//for(int j=0;j<=n;j++)printf("%lld %lld %lld %lld\n",i,j,dp[i][j],het[i][j]);
		}
		ans=0;
		for(int i=n;i>=1;i--)
		{
			if(b[i]=='0')continue;
			ans=(ans+het[n][i])%mod;
			if(b[i]=='1')break;
		}
		printf("%lld\n",ans);
	}
	return 0;
}