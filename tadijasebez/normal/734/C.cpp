#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
const int N=200050;
ll a[N],b[N],c[N],d[N];
ll min(ll a, ll b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
int main()
{
	ll n,s,x;
	int m,k,i,j;
	scanf("%lld %i %i",&n,&m,&k);
	scanf("%lld %lld",&x,&s);
	for(i=1;i<=m;i++) scanf("%lld",&a[i]);
	for(i=1;i<=m;i++) scanf("%lld",&b[i]);
	for(i=1;i<=k;i++) scanf("%lld",&c[i]);
	for(i=1;i<=k;i++) scanf("%lld",&d[i]);
	a[0]=x;
	ll sol=9e18;
	for(i=0;i<=m;i++)
	{
		if(b[i]>s) continue;
		j=upper_bound(d+1,d+1+k,s-b[i])-d-1;
		//printf("%i %i %lld\n",i,j,(max(n-c[j],0))*a[i]);
		sol=min(sol,(max(n-c[j],0))*a[i]);
	}
	printf("%lld\n",sol);
	return 0;
}