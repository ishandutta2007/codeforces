#include<bits/stdc++.h>
using namespace std;
const int max_n=2e3+5;
int cnt[max_n],dp[2][max_n][max_n],lim[max_n];
const int mod=998244353;
inline void add(int &a,int b)
{
	a+=b,a-=a>=mod?mod:0;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int a;
		scanf("%d",&a);
		++cnt[a];
	}
	for(int i=1;i<=n;++i)
	{
		int sum=0;
		for(int j=1;j<=n;++j)
			sum+=min(cnt[j],i);
		lim[i]=sum;
	}
	int sta=(n+1)&1;
	dp[sta][0][0]=1;
	for(int i=n;i>=1;--i)
	{
		int y=i&1,x=y^1;
		dp[y][0][0]=1;
		for(int j=1;i*j<=n;++j)
			for(int k=i*j;k<=lim[j];++k)
			{
				dp[y][j][k]=dp[x][j][k];
				dp[x][j][k]=0;
				add(dp[y][j][k],dp[y][j-1][k-i]);
			}
	}
	int ans=0;
	for(int j=1;j<=n;++j)
		add(ans,dp[1][j][n]);
	printf("%d\n",ans);
	return 0;
}