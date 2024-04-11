#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define ll long long
const int N=200050;
const ll inf=1e18;
ll min(ll a, ll b){ return a>b?b:a;}
ll t[N],u[N],v[N],b,c;
ll sol=inf;
multiset<ll> val;
void Solve(ll n, ll k)
{
	ll sum=0,i;
	val.clear();
	for(i=1;i<=k;i++)
	{
		sum+=(ll)(u[k]-u[i])*b/5+v[i];
		val.insert((ll)(u[k]-u[i])*b/5+v[i]);
	}
	ll lzy=0,fir=u[k];
	for(i=k;i<=n;i++)
	{
		lzy=u[i]-fir;
		sol=min(sol,sum+lzy*k*b/5);
		//printf("%i %i\n",i,sum+lzy*k*b/5);
		if(i!=n)
		{
			lzy=u[i+1]-fir;
			//printf("add:%lld\n",(ll)v[i+1]-lzy*b/5);
			sum+=(ll)v[i+1]-lzy*b/5;
			val.insert((ll)v[i+1]-lzy*b/5);
			ll del=*val.rbegin();
			sum-=del;
			//printf("del:%lld\n",del);
			val.erase(--val.end());
		}
	}
}
ll mod(ll x){ return (x%5+5)%5;}
int main()
{
	ll n,k,i,j;
	scanf("%lld %lld %lld %lld",&n,&k,&b,&c);
	b=min(b,c*5);
	for(i=1;i<=n;i++) scanf("%lld",&t[i]);
	sort(t+1,t+1+n);
	for(j=0;j<5;j++)
	{
		for(i=1;i<=n;i++)
		{
			if(mod(t[i])<=j) u[i]=t[i]+j-mod(t[i]),v[i]=(j-mod(t[i]))*c;
			else u[i]=t[i]+j-mod(t[i])+5,v[i]=(j-mod(t[i])+5)*c;
		}
		//printf("%i\n",j);
		Solve(n,k);
	}
	printf("%lld\n",sol);
	return 0;
}