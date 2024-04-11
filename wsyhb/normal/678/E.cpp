#include<bits/stdc++.h>
using namespace std;
const int max_n=18+5;
const int max_S=1<<18|5;
double p[max_n][max_n],dp[max_S][max_n];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			scanf("%lf",&p[i][j]);
	int U=(1<<n)-1;
	dp[U][0]=1;
	for(int S=U-1;S>=1;--S)
		for(int i=0;i<n;++i)
		{
			if(S>>i&1)
			{
				for(int j=0;j<n;++j)
				{
					if(~S>>j&1)
					{
						int T=S|(1<<j);
						dp[S][i]=max(dp[S][i],p[i][j]*dp[T][i]+p[j][i]*dp[T][j]);
					}
				}
			}
		}
	/*
	for(int S=1;S<=U;++S)
		for(int i=0;i<n;++i)
		{
			if(S>>i&1)
				fprintf(stderr,"S=%d i=%d dp[S][i]=%.4lf\n",S,i,dp[S][i]);
		}
	*/
	double ans=0;
	for(int i=0;i<n;++i)
		ans=max(ans,dp[1<<i][i]);
	printf("%.8lf\n",ans);
	return 0;
}