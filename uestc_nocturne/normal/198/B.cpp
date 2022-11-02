/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=200100;
int q[V],dp[V],n,K,i,j,top,tail;
char s[2][V];
int main()
{
	while(~scanf("%d%d",&n,&K))
	{
		scanf("%s%s",s[0],s[1]);
		s[0][n]=s[1][n]='-';n++;
		memset(dp,-1,sizeof(dp));
		dp[0]=0;
		top=0;tail=1;q[1]=0;
		while(top<tail)
		{
			top++;
			i=q[top];
			//printf("%d %d %d\n",i/n,i%n,dp[i]);
			if(i%n!=0)
			{
				j=i-1;
				if(s[j/n][j%n]=='-'&&dp[j]==-1&&j%n>=dp[i]+1)
				{
					dp[j]=dp[i]+1;
					tail++;q[tail]=j;
				}
			}
			if(i%n!=n-1)
			{
				j=i+1;
				if(s[j/n][j%n]=='-'&&dp[j]==-1&&j%n>=dp[i]+1)
				{
					dp[j]=dp[i]+1;
					tail++;q[tail]=j;
				}
			}
			j=((i/n)^1)*n+min(i%n+K,n-1);
			if(s[j/n][j%n]=='-'&&dp[j]==-1&&j%n>=dp[i]+1)
			{
				dp[j]=dp[i]+1;
				tail++;q[tail]=j;
			}			
		}
		if(dp[n-1]!=-1||dp[2*n-1]!=-1)puts("YES");
		else puts("NO");
	}
}