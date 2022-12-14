#include<cstdio>

using namespace std;

const long long mod=1000000007;

long long dp[1100100];

int one=0,two=0;

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int in;
		scanf("%d",&in);
		if(in==1) one++;
		else two++;
	}
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=one;i++)
	{
		dp[i]=dp[i-1]+dp[i-2]*(i-1);
		dp[i]%=mod;
	}
	long long res=dp[one];
	for(int i=one+1;i<=one+two;i++)
	{
		res*=i;
		res%=mod;
	}
	res+=mod;
	res%=mod;
	printf("%d\n",(int)res);
	return 0;
}