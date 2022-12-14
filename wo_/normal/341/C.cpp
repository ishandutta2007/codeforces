#include<cstdio>

using namespace std;

const long long mod=1000000007;

long long dp[2020][2020];
long long fact[2020];

bool pl[2020],va[2020];

int o,b;

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		pl[i]=true;
		va[i]=true;
	}
	for(int i=0;i<N;i++)
	{
		int in;
		scanf("%d",&in);
		in--;
		if(in>=0)
		{
			va[in]=false;
			pl[i]=false;
		}
	}
	for(int i=0;i<N;i++)
	{
		if(va[i]==true&&pl[i]==true) b++;
		else if(pl[i]==true) o++;
	}
	fact[0]=1;
	for(int i=1;i<=N;i++) fact[i]=(fact[i-1]*i)%mod;
	for(int i=0;i<=N;i++) dp[0][i]=fact[i];
	for(int i=1;i<=N;i++) for(int j=0;i+j<=N;j++)
	{
		dp[i][j]=0;
		if(i>=2)
		{
			dp[i][j]+=dp[i-2][j+1]*(i-1);
		}
		dp[i][j]%=mod;
		dp[i][j]+=dp[i-1][j]*(j);
		dp[i][j]%=mod;
	}
	long long ans=dp[b][o];
//	for(int i=1;i<=o;i++)
//	{
//		ans*=i;
//		ans%=mod;
//	}
	ans+=mod;
	ans%=mod;
	printf("%d\n",(int)ans);
	return 0;
}