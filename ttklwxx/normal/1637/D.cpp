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
bool dp[105][10005];
int a[1005],b[1005];
signed main()
{
	int t,n,ans=0,nans=0,pfh=0,het;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		pfh=0;
		het=0;
		for(int i=1;i<=n;i++)a[i]=read(),pfh+=a[i]*a[i],het+=a[i];
		for(int i=1;i<=n;i++)b[i]=read(),pfh+=b[i]*b[i],het+=b[i];
		if(n==1)
		{
			printf("0\n");
			continue;
		}
		dp[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=10000;j++)dp[i][j]=0;
			for(int j=0;j<=10000-a[i];j++)dp[i][j+a[i]]|=dp[i-1][j];
			for(int j=0;j<=10000-b[i];j++)dp[i][j+b[i]]|=dp[i-1][j];
		}
		ans=1121131433448687LL;
		for(int i=0;i<=10000;i++)
		{
			if(dp[n][i]==false)continue;
			nans=(n-2)*pfh+i*i+(het-i)*(het-i);
			ans=min(ans,nans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}