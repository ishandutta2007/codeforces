#include<bits/stdc++.h>
using namespace std;
const int max_n=100+5;
int p[max_n],dp[max_n][max_n][2];
const int inf=0x3f3f3f3f;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",p+i);
	memset(dp,0x3f,sizeof(dp));
	dp[1][0][0]=dp[1][1][1]=0;
	if(p[1])
		dp[1][!(p[1]&1)][!(p[1]&1)]=inf;
	for(int i=2;i<=n;++i)
		for(int j=0;j<=i-1;++j)
			for(int k=0;k<=1;++k)
			{
				int v=dp[i-1][j][k];
				if(v!=inf)
				{
//					fprintf(stderr,"i=%d j=%d k=%d dp[i][j][k]=%d\n",i-1,j,k,dp[i-1][j][k]);
					int t;
					if(!(p[i]&1))
					{
						t=0;
						dp[i][j+t][t]=min(dp[i][j+t][t],v+(t!=k));
					}
					if(!p[i]||(p[i]&1))
					{
						t=1;
						dp[i][j+t][t]=min(dp[i][j+t][t],v+(t!=k));
					}
				}
			}
	int cnt=(n+1)/2;
	int ans=min(dp[n][cnt][0],dp[n][cnt][1]);
	printf("%d\n",ans);
	return 0;
}