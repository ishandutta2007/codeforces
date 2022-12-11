#include<bits/stdc++.h>
using namespace std;
int n;
const int max_n=200+5;
int c[max_n][max_n],root[max_n][max_n];
long long sum[max_n][max_n],dp[max_n][max_n];
inline long long query(int l,int r)
{
	if(l>r)
		return 0;
	return (sum[r][n]-sum[l-1][n])-(sum[r][r]-sum[r][l-1]-sum[l-1][r]+sum[l-1][l-1]);
}
int ans[max_n];
inline int solve(int l,int r)
{
	if(l>r)
		return 0;
	int rt=root[l][r];
	int ls=solve(l,rt-1);
	int rs=solve(rt+1,r);
	ans[ls]=ans[rs]=rt;
	return rt;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			scanf("%d",&c[i][j]);
			sum[i][j]=sum[i-1][j]+sum[i][j-1]+c[i][j]-sum[i-1][j-1];
		}
	for(int l=1;l<=n;++l)	
		for(int i=1;i+l-1<=n;++i)
		{
			int j=i+l-1;
			dp[i][j]=1e18;
			for(int k=i;k<=j;++k)
			{
				long long val=dp[i][k-1]+dp[k+1][j]+query(i,k-1)+query(k+1,j);
				if(val<dp[i][j])
				{
					dp[i][j]=val;
					root[i][j]=k;
				}
			}
		}
	solve(1,n);
	for(int i=1;i<=n;++i)
		printf("%d%c",ans[i],i<n?' ':'\n');
	return 0;
}