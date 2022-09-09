#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
int main()
{
	ll n,m,k,d,i,j;
	scanf("%lld %lld %lld %lld",&n,&k,&m,&d);
	ll sol=0;
	for(i=1;i<=d;i++)
	{
		if((i-1)*k+1>n) break;
		j=min(m,n/((i-1)*k+1));
		sol=max(sol,i*j);
	}
	printf("%lld\n",sol);
	return 0;
}