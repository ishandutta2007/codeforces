using namespace std;
#include<bits/stdc++.h>
#define N 30
int dp[1<<25];
int n,m;
int a[N][N];
#define r(x) scanf("%d",&x)
#define F(i,a,b) for(int i=a;i<=b;i++) 
int qi[N][N];
int st[N][N];
char c[N][N];
int lowbit(int x)
{
	return (x&(-x));
}
int main()
{
	r(n);r(m);
	for(int i=1;i<=n;i++) scanf("%s",c[i]+1);
	F(i,1,n)
	F(j,1,m) 
	r(a[i][j]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int it=-2e9,sum=0;
			for(int k=1;k<=n;k++)
			{
				if(c[k][j]==c[i][j])
				{
					st[i][j]|=(1<<(k-1));
					sum+=a[k][j];
					it=max(it,a[k][j]);
				} 
			}
			sum-=it;
			qi[i][j]=sum;
					}
	}
	for(int i=0;i<=(1<<n)-1;i++) dp[i]=2e9;
	dp[0]=0;
	for(int i=0;i<=(1<<n)-1;i++)
	{
		int k;
		for(k=0;k<=n;k++)
		if(!((1<<k)&i))
		{
			break;
		}
		for(int j=1;j<=m;j++)
		{
			dp[i|(1<<k)]=min(dp[i|(1<<k)],dp[i]+a[k+1][j]);
			dp[i|st[k+1][j]]=min(dp[i]+qi[k+1][j],dp[i|st[k+1][j]]);
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
}