#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
const int N=1000050;
const int S=3163;
bool sieve[N];
vector<int> primes,tmp;
int Sol[10000000];
void FindPrimes()
{
	int i,j;
	for(i=2;i<S;i++)
	{
		if(!sieve[i])
		{
			primes.push_back(i);
			for(j=i;j<S;j+=i) sieve[j]=true;
		}
	}
}
ll dp[N];
void Add(int x)
{
	int i;
	for(i=0;i<primes.size();i++)
	{
		if(x%primes[i]==0)
		{
			Sol[primes[i]]++;
			while(x%primes[i]==0) x/=primes[i];
		}
	}
	if(x>1)
	{
		Sol[x]++;
		tmp.push_back(x);
	}
}
void DP()
{
	sort(tmp.begin(),tmp.end());
	//tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
	vector<int> tmp1;//printf(":D\n");
	if(!tmp.empty()) tmp1.push_back(tmp[0]);
	int i;
	for(i=1;i<tmp.size();i++) if(tmp[i]!=tmp1[tmp1.size()-1]) tmp1.push_back(tmp[i]);
	for(i=0;i<tmp1.size();i++) primes.push_back(tmp1[i]);
	for(i=0;i<primes.size();i++) dp[i+1]=dp[i]+Sol[primes[i]];
}
ll Solve(int l, int r)
{
	l=lower_bound(primes.begin(),primes.end(),l)-primes.begin();
	r=upper_bound(primes.begin(),primes.end(),r)-primes.begin();
	return dp[r]-dp[l];
}
int main()
{
	FindPrimes();
	int n,q,i,l,r,x;
	scanf("%i",&n);
	while(n--) scanf("%i",&x),Add(x);
	DP();
	scanf("%i",&q);
	while(q--) scanf("%i %i",&l,&r),printf("%lld\n",Solve(l,r));
	return 0;
}