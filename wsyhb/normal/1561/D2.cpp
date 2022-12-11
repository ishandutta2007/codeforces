#include<bits/stdc++.h>
using namespace std;
int n,m;
inline int get_sum(int a,int b)
{
	return a+b-(a+b>=m?m:0);
}
const int max_n=4e6+5;
int dp[max_n],sum[max_n];
int main()
{
	scanf("%d%d",&n,&m);
	dp[n]=sum[n]=1;
	for(int x=n-1;x>=1;--x)
	{
		dp[x]=sum[x+1];
		for(int i=2;x*i<=n;++i)
		{
			int l=x*i,r=min((x+1)*i-1,n);
			dp[x]+=sum[l]-sum[r+1];
			dp[x]-=dp[x]>=m?m:0;
			dp[x]+=dp[x]<0?m:0;
		}
		sum[x]=get_sum(sum[x+1],dp[x]);
	}
	printf("%d\n",dp[1]);
	return 0;
}