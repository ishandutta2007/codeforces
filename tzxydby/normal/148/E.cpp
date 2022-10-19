#include<bits/stdc++.h>
using namespace std;
const int N=105;
int t[N],tt[N],sum[N],a[N],mc[N][N],dp[N][N*N];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);
		tt[i]=tt[i-1]+t[i];
		for(int j=1;j<=t[i];j++)
		{
			scanf("%d",&a[j]);
			sum[j]=sum[j-1]+a[j];
		}
		for(int j=1;j<=t[i];j++)
			for(int k=0;k<=j;k++)
				mc[i][j]=max(mc[i][j],sum[k]-sum[0]+sum[t[i]]-sum[t[i]-(j-k)]);
	}
	for(int i=1;i<=t[1];i++)
		dp[1][i]=mc[1][i];
	for(int i=2;i<=n;i++)
		for(int j=0;j<=tt[i];j++)
			for(int k=0;k<=t[i];k++)
				if(j>=k&&tt[i-1]>=j-k)
					dp[i][j]=max(dp[i][j],dp[i-1][j-k]+mc[i][k]);
	printf("%d\n",dp[n][m]); 
	return 0;
}