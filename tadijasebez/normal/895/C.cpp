#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define ll long long
const int S=70;
const int N=1<<19;
const int mod=1e9+7;
vector<int> Prime;
bool sieve[S];
void FindPrimes()
{
	int i,j;
	for(i=2;i<S;i++)
	{
		if(!sieve[i])
		{
			Prime.pb(i);
			for(j=i;j<S;j+=i) sieve[j]=1;
		}
	}
}
int pow(int x, int k)
{
	int ret=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;
	return ret;
}
int cnt[N],c,p=1,dp[N][2];
int main()
{
	FindPrimes();
	int n,i,x,j;
	scanf("%i",&n);
	while(n--)
	{
		scanf("%i",&x);
		int msk=0;
		for(i=0;i<Prime.size();i++)
		{
			int k=0;
			while(x%Prime[i]==0) k^=1,x/=Prime[i];
			msk+=(1<<i)*k;
		}
		cnt[msk]++;
	}
	dp[0][p]=1;
	for(i=0;i<N;i++)
	{
		if(!cnt[i]) continue;
		int exp=pow(2,cnt[i]-1);
		for(j=0;j<N;j++) dp[j][c]=0;
		for(j=0;j<N;j++)
		{
			dp[j^i][c]+=(ll)exp*dp[j][p]%mod;
			if(dp[j^i][c]>=mod) dp[j^i][c]-=mod;
			dp[j][c]+=(ll)exp*dp[j][p]%mod;
			if(dp[j][c]>=mod) dp[j][c]-=mod;
		}
		c^=1;
		p^=1;
	}
	printf("%i\n",dp[0][p]-1);
	return 0;
}