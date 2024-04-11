#include<iostream>
#include<cstdio>
#include<cmath>
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
bool dp[1001][1001];int a[1001],b[1001];
signed main()
{
	int n,k,sum=0,ans=0;
	n=read();
	k=read();
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		b[i]=read();
		sum=(sum+a[i]+b[i]);
		for(int j=0;j<k;j++)
		{
			dp[i][j]=dp[i-1][(k+j-a[i]%k)%k];
			for(int s=0;s<=min(k-1,a[i]);s++)
			{
				if(b[i]>=k-(a[i]-s)%k)
				dp[i][j]|=dp[i-1][(j-s+k)%k];
			}
		}
	}
	for(int i=0;i<k;i++)if(dp[n][i])ans=max(ans,(sum-i)/k);
	printf("%lld\n",ans);
	return 0;
}