#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=5050;
const int inf=1e9+7;
int dp[N][N][3],a[N];
int main()
{
	int n,i,j,k,l;
	scanf("%i",&n);k=(n+1)/2;
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=0;i<=n;i++) for(j=0;j<=k;j++) for(l=0;l<3;l++) dp[i][j][l]=inf;
	dp[1][0][2]=0;
	dp[1][1][0]=0;
	for(i=2;i<=n;i++)
	{
		for(j=0;j<=k;j++)
		{
			int cost=a[i-1]-a[i]+1;
			if(a[i-1]<a[i]) cost=0;
			if(j>0) dp[i][j][0]=min(dp[i][j][0],dp[i-1][j-1][2]+cost);
			int h=min(a[i],a[i-2]);
			cost=a[i-1]-h+1;
			if(a[i-1]<h) cost=0;
			if(i>2 && j>0) dp[i][j][0]=min(dp[i][j][0],dp[i-2][j-1][0]+cost);
			cost=a[i]-a[i-1]+1;
			if(a[i]<a[i-1]) cost=0;
			dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][0]+cost);
			dp[i][j][2]=min(dp[i-1][j][2],dp[i-1][j][1]);
			//printf("(%i %i)=%i %i %i\n",i,j,dp[i][j][0],dp[i][j][1],dp[i][j][2]);
		}
	}
	for(i=1;i<=k;i++) printf("%i ",min(dp[n][i][0],min(dp[n][i][1],dp[n][i][2])));
    return 0;
}