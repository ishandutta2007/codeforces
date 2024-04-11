#include<iostream>
#include<cstdio>
#include<map>
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
int dp[200005][10][10],tdp[10];
int main()
{
	int t,n,m,ans;
	t=read();
	for(int sth=0;sth<=9;sth++)
	{
		dp[0][sth][sth]=1;
		for(int i=1;i<=200000;i++)
		{
			for(int j=0;j<=9;j++)tdp[j]=dp[i-1][j][sth];
			for(int j=1;j<=9;j++)dp[i][j][sth]=tdp[j-1];
			dp[i][0][sth]=tdp[9];
			dp[i][1][sth]=(dp[i][1][sth]+tdp[9])%mod;
		}
	}
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		ans=0;
		while(n!=0)
		{
			for(int i=0;i<=9;i++)ans=(ans+dp[m][i][n%10])%mod;
			n/=10;
		}
		printf("%d\n",ans);
	}
	return 0;
}