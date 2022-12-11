#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int dp[2][max_n],sum[2][max_n],ans[max_n];
const int mod=998244353;
inline void add(int &a,int b)
{
	a+=b,a-=a>=mod?mod:0;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	dp[0][0]=1;
	for(int i=0;i<=n;i+=k)
		sum[0][i]=1;
	for(int i=1;i<=632;++i)
	{
		int y=i&1,x=y^1,d=k+i-1;
		for(int j=0;j<=n;++j)
			dp[y][j]=sum[y][j]=0;
		for(int j=d;j<=n;++j)
		{
			dp[y][j]=sum[x][j-d];
			sum[y][j]=dp[y][j];
			if(j>=d+1)
				add(sum[y][j],sum[y][j-(d+1)]);
		}
		for(int j=1;j<=n;++j)
			add(ans[j],dp[y][j]);
	}
	for(int j=1;j<=n;++j)
		printf("%d%c",ans[j]," \n"[j==n]);
	return 0;
}