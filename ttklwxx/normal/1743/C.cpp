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
int a[200005];
int dp[200005][2];
char s[200005];
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)a[i]=read();
		a[0]=0;
		dp[0][0]=0;
		dp[0][1]=-2000000000;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')
			{
				dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
				dp[i][1]=-2000000000;
			}
			else
			{
				dp[i][0]=dp[i-1][0]+a[i-1];
				dp[i][1]=max(dp[i-1][0],dp[i-1][1])+a[i];
			}
		}
		printf("%d\n",max(dp[n][0],dp[n][1]));
	}
	return 0;
}