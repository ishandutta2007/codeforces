#include <stdio.h>
#include <vector>
using namespace std;
const int inf=1e9;
const int L=30;
int dp[L];
bool sieve[L];
vector<int> NotPrime;
void FindComposites()
{
	int i,j;
	for(i=2;i<L;i++)
	{
		if(!sieve[i])
		{
			for(j=i+i;j<L;j+=i)
			{
				if(!sieve[j]) NotPrime.push_back(j);
				sieve[j]=true;
			}
		}
	}
}
int max(int a, int b){ return a>b?a:b;}
void DP()
{
	FindComposites();
	int i,j;
	for(i=0;i<L;i++) dp[i]=-inf;
	dp[0]=0;
	for(i=1;i<L;i++)
	{
		for(j=0;j<NotPrime.size();j++)
		{
			int v=NotPrime[j];
			if(v<=i) dp[i]=max(dp[i],dp[i-v]+1);
		}
	}
}
int Query(int x)
{
	if(x<L) return dp[x];
	int ret=-inf;
	for(int i=0;i<L;i++)
	{
		if((x-i)%4==0)
		{
			ret=max(ret,dp[i]+(x-i)/4);
		}
	}
	return ret;
}
int Get(int x){ int ans=Query(x);if(ans<0) return -1; return ans;}
int main()
{
	int n,x;
	DP();
	scanf("%i",&n);
	while(n--) scanf("%i",&x),printf("%i\n",Get(x));
	return 0;
}