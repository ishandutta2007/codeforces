#include<iostream>
#include<cstdio>
#include<cstring>
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
char str[2][200005];
int dp[200005],ls[200005];
int main()
{
	int t,n,l,r;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",str[0]+1);
		scanf("%s",str[1]+1);
		dp[0]=0;
		for(int i=1;i<=n;i++)
		{
			ls[i]=0;
			if(str[0][i]=='0')ls[i]++;
			if(str[1][i]=='0')ls[i]++;
		}
		if(ls[1]==0)dp[1]=0;
		else if(ls[1]==1)dp[1]=2;
		else dp[1]=1;
		for(int i=2;i<=n;i++)
		{
			if(ls[i]==1)dp[i]=dp[i-1]+2;
			else if(ls[i]==0)
			{
				if(ls[i-1]==2)dp[i]=dp[i-2]+2;
				else dp[i]=dp[i-1];
			}
			else
			{
				if(ls[i-1]==1||ls[i-1]==2)dp[i]=dp[i-1]+1;
				else dp[i]=dp[i-2]+2;
			}
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}