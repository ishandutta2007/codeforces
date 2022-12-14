#include<cstdio>
#include<algorithm>

using namespace std;

const int inf=1<<29;

int dp[5050];
int a[5050];

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		double d;
		scanf("%d%lf",a+i,&d);
	}
	for(int i=0;i<N;i++) dp[i]=inf;
	for(int i=0;i<N;i++)
	{
		*upper_bound(dp,dp+N,a[i])=a[i];
	}
	printf("%d\n",N-(lower_bound(dp,dp+N,inf)-dp));
	return 0;
}