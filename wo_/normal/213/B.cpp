#include<cstdio>

using namespace std;

const long long mod=1000000007;

long long C[220][220];

long long dp[11][110];

void getC()
{
	for(int i=0;i<220;i++)
	{
		C[i][i]=1;
		C[i][0]=1;
	}
	for(int i=2;i<220;i++) for(int j=1;j<i;j++)
	{
		C[i][j]=C[i-1][j-1]+C[i-1][j];
		C[i][j]%=mod;
	}
}

int main()
{
	getC();
	int N;
	scanf("%d",&N);
	int a[10];
	for(int i=0;i<10;i++) scanf("%d",a+i);
	dp[10][0]=1;
	for(int i=9;i>=1;i--)
	{
		for(int j=0;j<=100;j++)
		{
			dp[i][j]=0;
			for(int k=0;k<=j;k++)
			{
				if(j-k<a[i]) continue;
				dp[i][j]+=(dp[i+1][k]*C[j][k]);
				dp[i][j]%=mod;
			}
		}
	}
	for(int j=0;j<=100;j++)
	{
		dp[0][j]=0;
		for(int k=1;k<=j;k++)
		{
			if(j-k<a[0]) continue;
			dp[0][j]+=(dp[1][k]*C[j-1][k-1]);
			dp[0][j]%=mod;
		}
	}
	long long ans=0;
	for(int i=1;i<=N;i++)
	{
		ans+=dp[0][i];
		ans%=mod;
	}
	ans+=mod;
	ans%=mod;
	printf("%d\n",(int)ans);
	return 0;
}