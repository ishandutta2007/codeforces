#include <bits/stdc++.h>
using namespace std;
const int N=2005;
double dp[N][N];
int main()
{
	int t,n,i,j;
	double p;
	//scanf("%i %llf %i",&n,&p,&t);
	cin >> n >> p >> t;
	dp[0][0]=1;
	for(i=1;i<=t;i++)
	{
		for(j=1;j<=n;j++)
		{
			dp[i][j]=p*dp[i-1][j-1]+(1.0-p)*dp[i-1][j];
			if(j==n) dp[i][j]+=dp[i-1][j]*p;
		}
		dp[i][0]=dp[i-1][0]*(1.0-p);
	}
	double sol=0;
	for(i=0;i<=n;i++) sol+=dp[t][i]*i;
	//printf("%.12llf\n",sol);
	cout << setprecision(12) << sol << "\n";
	//for(i=1;i<=t;i++) for(j=0;j<=n;j++) printf("%llf%c",dp[i][j],j==n?'\n':' ');
	return 0;
}