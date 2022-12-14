#include<cstdio>
#include<cstring>

using namespace std;

long long dp[55][55][55];//[thought people(0..i-1)][selected people][length];
long long C[55][55];

int a[55];

int main()
{
	int N,p;
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",a+i);
	scanf("%d",&p);
	memset(dp,0,sizeof(dp));
	dp[0][0][0]=1;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			for(int k=0;k<=p;k++)
			{
				dp[i+1][j][k]+=dp[i][j][k];
				int nxt=k+a[i];
				if(nxt>p) continue;
				dp[i+1][j+1][nxt]+=dp[i][j][k];
			}
		}
	}
	memset(C,0,sizeof(C));
	for(int i=1;i<=N;i++)
	{
		C[i][0]=1;
		C[i][i]=1;
	}
	for(int i=2;i<=N;i++)
	{
		for(int j=1;j<i;j++)
		{
			C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
	}
	double ans=0;
	for(int i=1;i<=p;i++)
	{
		for(int j=1;j<=N;j++)
		{
			ans+=(double)dp[N][j][i]/C[N][j];
		}
	}
	printf("%.9f\n",ans);
	return 0;
}