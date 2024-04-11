#include<iostream>
#include<cstdio>
#define maxn 262143
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
int dp[101][101];
int main()
{
	int k;
	k=read();
	printf("3 3\n");
	dp[1][1]=maxn;
	dp[1][2]=k;
	dp[2][1]=131072;
	dp[1][3]=dp[2][2]=dp[2][3]=dp[3][1]=dp[3][2]=maxn;
	dp[3][3]=k;
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
	return 0;
}