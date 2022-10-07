#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll n,k,a,b;
ll maxx=0,minn=1000000000000000000;
int main()
{
	scanf("%I64d%I64d",&n,&k);
	scanf("%I64d%I64d",&a,&b);
	for(int i=0;i<=n;i++)
	{
		ll x=1ll*i*k-b;
		maxx=max(maxx,abs(1ll*n*k/__gcd(1ll*n*k,x-a)));
		minn=min(minn,abs(1ll*n*k/__gcd(1ll*n*k,x-a)));
		x=1ll*i*k+b;
		maxx=max(maxx,abs(1ll*n*k/__gcd(1ll*n*k,x-a)));
		minn=min(minn,abs(1ll*n*k/__gcd(1ll*n*k,x-a)));
	}
	a=k-a;
	for(int i=0;i<=n;i++)
	{
		ll x=1ll*i*k-b;
		maxx=max(maxx,abs(1ll*n*k/__gcd(1ll*n*k,x-a)));
		minn=min(minn,abs(1ll*n*k/__gcd(1ll*n*k,x-a)));
		x=1ll*i*k+b;
		maxx=max(maxx,abs(1ll*n*k/__gcd(1ll*n*k,x-a)));
		minn=min(minn,abs(1ll*n*k/__gcd(1ll*n*k,x-a)));
	}
	printf("%I64d %I64d\n",minn,maxx);
	return 0;
}