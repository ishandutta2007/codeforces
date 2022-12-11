#include<bits/stdc++.h>
#define maxn 2005
using namespace std;
int n,t;
double p;
double dp[maxn][maxn];
int main()
{
	scanf("%d%lf%d",&n,&p,&t);
	dp[0][0]=1;
	for(int i=0;i<t;++i)
	{
		for(int j=0;j<=n;++j)
		{
			if(j<n)
			{
				dp[i+1][j]+=dp[i][j]*(1-p);
				dp[i+1][j+1]+=dp[i][j]*p;
			}
			else dp[i+1][j]+=dp[i][j];
		}
	}
	double ans=0;
	for(int j=0;j<=n;++j)ans+=dp[t][j]*j;
	printf("%.10f\n",ans);
	return 0;
}