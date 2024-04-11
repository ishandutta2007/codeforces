#include<iostream>
#include<cstdio>
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
int dp[5005][5005],sy[5005],pos[5005],cnt;
inline int jdz(int x)
{
	if(x<0)return -x;
	return x;
}
signed main()
{
	int n;
	n=read();
	for(int i=1;i<=n;i++)sy[i]=read();
	for(int i=1;i<=n;i++)
	{
		if(sy[i]==1)pos[++cnt]=i;
	}
	for(int i=0;i<=n+1;i++)for(int j=0;j<=cnt;j++)dp[i][j]=1121131433448687LL;
	dp[1][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=cnt;j++)
		{
			if(dp[i][j]==1121131433448687LL)continue;
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
			if(j!=cnt&&sy[i]==0)
			{
				dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+jdz(pos[j+1]-i));
			}
		}
	}
	printf("%lld\n",dp[n+1][cnt]);
	return 0;
}