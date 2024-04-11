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
int a[1001],b[1001];
bool dp[1001][1001];
int main()
{
	int n,m;
	n=read();
	m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)b[i]=read();
	dp[0][0]=true;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<512;j++)
		{
			if(dp[i-1][j]==true)
			{
				for(int k=1;k<=m;k++)dp[i][j|(a[i]&b[k])]=true;
			}
		}
	}
	for(int i=0;i<=511;i++)
	{
		if(dp[n][i]==true)
		{
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}