#include <stdio.h>
#include <vector>
using namespace std;
const int N=5000500;
const int S=2237;
vector<int> primes;
bool sieve[S];
void FindPrimes()
{
	int i,j;
	for(i=2;i<S;i++)
	{
		if(!sieve[i])
		{
			primes.push_back(i);
			for(j=i*2;j<S;j+=i) sieve[j]=true;
		}
	}
}
/*bool prime[N];
void Sieve()
{
	int i,j;
	for(i=2;i<N;i++)
	{
		if(!prime[i]) for(j=i*2;j<N;j+=i) prime[j]=true;
	}
}*/
long long dp[N];
void Preprocess()
{
	int i,j,k;
	FindPrimes();
	//Sieve();
	for(i=1;i<N;i++)
	{
		//k=i;
		//if(!prime[k] && k>S) dp[i]++;
		if(dp[i]==0 && i>1) dp[i]=1;
		for(j=0;j<primes.size();j++)
		{
			if(N/i>=primes[j]) dp[i*primes[j]]=dp[i]+1;
			//while(k%primes[j]==0) dp[i]++,k/=primes[j];
		}
		//if(k>1) dp[i]++;
		dp[i]+=dp[i-1];
	}
}
int main()
{
	int t,a,b;
	Preprocess();
	scanf("%i",&t);
	while(t--)
	{
		scanf("%i %i",&a,&b);
		printf("%lld\n",dp[a]-dp[b]);
	}
	return 0;
}