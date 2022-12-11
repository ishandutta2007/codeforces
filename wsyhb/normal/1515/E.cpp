#include<bits/stdc++.h>
using namespace std;
const int max_n=400+5;
int dp[max_n][max_n],C[max_n][max_n],Pow2[max_n];
int main()
{
	int n,M;
	scanf("%d%d",&n,&M);
	for(int i=0;i<=n;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)
		{
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			C[i][j]-=C[i][j]>=M?M:0;
		}
	}
	Pow2[0]=1;
	for(int i=1;i<=n;++i)
	{
		Pow2[i]=Pow2[i-1]<<1;
		Pow2[i]-=Pow2[i]>=M?M:0;
	}
	dp[0][0]=1;
	for(int i=0;i<=n;++i)
		for(int j=0;j<=i;++j)
		{
			int v=dp[i][j];
			if(v)
			{
				for(int k=1;i+k<=n;++k)
					dp[i+k+1][j+k]=(dp[i+k+1][j+k]+1ll*v*Pow2[k-1]%M*C[j+k][j])%M;
			}
		}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		ans+=dp[n+1][i];
		ans-=ans>=M?M:0;
	}
	printf("%d\n",ans);
	return 0;
}