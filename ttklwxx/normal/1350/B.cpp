#include<iostream>
#include<cstdio>
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
int a[200001],dp[200001];
signed main()
{
	int t,n,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read(),dp[i]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j+=i)if(a[i]<a[j])dp[j]=max(dp[j],dp[i]+1);
		}
		ans=0;
		for(int i=1;i<=n;i++)ans=max(ans,dp[i]);
		printf("%d\n",ans);
	}
	return 0;
}