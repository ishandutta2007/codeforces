#include<iostream>
#include<cstdio>
#include<cstring>
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
char s[300005];
int dp[300005][2];
signed main()
{
	int t,n,ans=0,x;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		dp[0][0]=dp[0][1]=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')
			{
				dp[i][1]=0;
				dp[i][0]=dp[i-1][1]+1;
			}
			else if(s[i]=='1')
			{
				dp[i][0]=0;
				dp[i][1]=dp[i-1][0]+1;
			}
			else
			{
				dp[i][0]=dp[i-1][1]+1;
				dp[i][1]=dp[i-1][0]+1;
			}
		}
		x=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='?')x++;
			else
			{
				ans-=x*(x+1)/2;
				x=0;
			}
		}
		ans-=x*(x+1)/2;
		for(int i=1;i<=n;i++)ans+=dp[i][0]+dp[i][1];
		printf("%lld\n",ans);
	} 
	return 0;
}