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
int dp[5005][5005],a[5005],sl[5005],c[5005][5005];
int jc[5005],njc[5005];
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
int main()
{
	c[0][0]=1;
	for(int i=1;i<=5000;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
	jc[0]=1;
	for(int i=1;i<=5000;i++)jc[i]=1LL*i*jc[i-1]%mod;
	njc[5000]=ksm(jc[5000],mod-2);
	for(int i=4999;i>=0;i--)njc[i]=1LL*(i+1)*njc[i+1]%mod;
	int t,n,sth,psl,maxn,gre;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		maxn=0;
		for(int i=1;i<=n;i++)sl[i]=0;
		for(int i=1;i<=n;i++)a[i]=read(),sl[a[i]]++,maxn=max(maxn,a[i]);
		if(n==2)
		{
			if(a[1]==a[2])printf("0\n");
			else printf("1\n");
			continue;
		}
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)dp[i][j]=0;
		}
		sl[maxn]--;
		if(sl[maxn]>0)
		{
			printf("0\n");
			continue;
		}
		dp[0][0]=1;
		psl=0;
		sth=0;
		gre=0;
		for(int i=1;i<=n;i++)
		{
			if(sl[i]==0)
			{
				for(int j=0;j<=psl;j++)dp[i][j]=dp[i-1][j];
				continue;
			}
			for(int j=0;j<=psl;j++)dp[i][j+sl[i]]=1LL*dp[i-1][j]*njc[sl[i]]%mod;
			for(int k=0;k<=psl;k++)
			{
				if(k==psl)
				{
					if(psl<2)continue;
					dp[i][sl[i]+k-3]=(dp[i][sl[i]+k-3]+1LL*dp[i-1][k]*sth%mod*njc[sl[i]-1]%mod)%mod;
				}
				else
				{
					dp[i][sl[i]+k-2]=(dp[i][sl[i]+k-2]+1LL*dp[i-1][k]*k%mod*njc[sl[i]-1]%mod)%mod;
				}
			}
			sth=(sth+sl[i]*psl*2)%mod;
			gre++; 
			sth=(sth+1LL*sl[i]*(sl[i]-1)%mod)%mod;
			//if(sl[i]>=2)sth+=2;
			psl+=sl[i];
			//for(int k=0;k<=psl;k++)printf("%lld %lld %lld\n",i,k,dp[i][k]);
			//printf("orz%lld %lld\n",i,sth);
		}
		printf("%d\n",dp[n][0]);
	}
	return 0;
}