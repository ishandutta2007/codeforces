#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
const int N=2000050;
const int S=1000;
const int mod=1e9+7;
ll pow(int x, int k)
{
	int ret=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;
	return ret;
}
bool sieve[S];
vector<int> prime;
void FindPrimes()
{
	int i,j;
	for(i=2;i<S;i++)
	{
		if(!sieve[i])
		{
			prime.push_back(i);
			for(j=i;j<S;j+=i) sieve[j]=1;
		}
	}
}
int F[N],I[N];
int Calc(int n, int k)
{
	return (ll)F[n]*I[k]%mod*I[n-k]%mod;
}
int main()
{
	int i,q,y,x;
	FindPrimes();
	F[0]=1;
	for(i=1;i<N;i++) F[i]=(ll)F[i-1]*i%mod;
	I[N-1]=pow(F[N-1],mod-2);
	for(i=N-2;i>=0;i--) I[i]=(ll)I[i+1]*(i+1)%mod;
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i",&x,&y);
		int ans=1,cnt;
		for(i=0;i<prime.size();i++)
		{
			cnt=0;
			while(x%prime[i]==0) cnt++,x/=prime[i];
			ans=(ll)ans*Calc(y+cnt-1,cnt)%mod;
		}
		if(x>1) ans=(ll)ans*y%mod;
		ans=(ll)ans*pow(2,y-1)%mod;
		printf("%i\n",ans);
	}
	return 0;
}