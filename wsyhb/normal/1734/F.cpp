#include<bits/stdc++.h>
using namespace std;
long long dp[62][4][2][3];
inline int calc(int x,int y)
{
	if(x<y)
		return 0;
	if(x==y)
		return 1;
	return 2;
}
inline int calc2(int x,int y)
{
	if(x!=1)
		return x;
	return y;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n,m;
		scanf("%lld%lld",&n,&m);
		memset(dp,0,sizeof(dp));
		dp[0][n&1][(n&1)!=0][calc(0,m&1)]=1;
		dp[0][(n&1)+1][(n&1)!=0][calc(1,m&1)]=1;
		for(int i=1;i<=61;++i)
		{
			int a=n>>i&1,b=m>>i&1;
			for(int j=0;j<=3;++j)
				for(int k=0;k<=1;++k)
					for(int l=0;l<=2;++l)
					{
						long long v=dp[i-1][j][k][l];
						if(!v)
							continue;
						dp[i][j/2+a][k^((j/2+a)%2!=0)][calc2(calc(0,b),l)]+=v;
						dp[i][j/2+1+a][k^((j/2+1+a)%2!=1)][calc2(calc(1,b),l)]+=v;
					}
		}
		long long ans=0;
		for(int j=0;j<=3;++j)
			ans+=dp[61][j][1][0];
		printf("%lld\n",ans);
	}
	return 0;
}