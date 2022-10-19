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
double qa[2005],qb[2005];
double dp[2005][2005];
int sl[2005][2005];
int main()
{
	int n,a,b;
	n=read();
	a=read();
	b=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&qa[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&qb[i]);
	}
	double l=0,r=1,mid;
	for(int sth=1;sth<=50;sth++)
	{
		mid=(l+r)/2;
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				dp[i][j]=-1000000000;
				sl[i][j]=0;
			}
		}
		dp[0][0]=0;
		sl[0][0]=0;
		for(int i=1;i<=n;i++)
		{
			if(qb[i]-mid>0)
			{
				dp[i][0]=dp[i-1][0]+qb[i]-mid;
				sl[i][0]=sl[i-1][0]+1;
			}
			else
			{
				dp[i][0]=dp[i-1][0];
				sl[i][0]=sl[i-1][0];
			}
			for(int j=1;j<=i;j++)
			{
				dp[i][j]=dp[i-1][j];
				sl[i][j]=sl[i-1][j];
				if(dp[i-1][j-1]+qa[i]>dp[i][j]-1e-10)
				{
					dp[i][j]=dp[i-1][j-1]+qa[i];
					sl[i][j]=sl[i-1][j-1];
				}
				if(dp[i-1][j]+qb[i]-mid>dp[i][j]-1e-10)
				{
					dp[i][j]=dp[i-1][j]+qb[i]-mid;
					sl[i][j]=sl[i-1][j]+1;
				}
				if(dp[i-1][j-1]+qa[i]+qb[i]-qa[i]*qb[i]-mid>dp[i][j]-1e-10)
				{
					dp[i][j]=dp[i-1][j-1]+qa[i]+qb[i]-qa[i]*qb[i]-mid;
					sl[i][j]=sl[i-1][j-1]+1;
				}
			}
			//printf("%lf %d\n",dp[i][1],sl[i][1]);
		}
	//	printf("%lf %lf %d\n",mid,dp[n][a],sl[n][a]);
		if(sl[n][a]>=b)l=mid;
		else r=mid;
	}
	printf("%.9lf\n",dp[n][a]+mid*b);
	return 0;
}