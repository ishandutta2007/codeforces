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
int lcp[5005][5005];
char str[200005]; 
int dp[5005];
signed main()
{
	int t,n,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",str+1);
		str[n+1]=0;
		for(int i=n;i>=1;i--)
		{
			for(int j=n;j>=1;j--)
			{
				if(str[i]!=str[j])lcp[i][j]=0;
				else if(i==n||j==n)lcp[i][j]=1;
				else lcp[i][j]=lcp[i+1][j+1]+1;
			}
		}
		for(int i=1;i<=n;i++)dp[i]=n-i+1;
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=i-1;j++)
			{
				if(str[i+lcp[i][j]]>str[j+lcp[i][j]])dp[i]=max(dp[i],dp[j]+n-i+1-lcp[i][j]);
			}
		}
		ans=0;
		for(int i=1;i<=n;i++)ans=max(ans,dp[i]);
		printf("%lld\n",ans);
	}
	return 0;
}