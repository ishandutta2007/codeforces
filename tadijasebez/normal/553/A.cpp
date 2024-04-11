#include <stdio.h>
#define ll long long
const int mod=1e9+7;
const int N=1050;
ll pow(ll x, int p)
{
	ll ret=1;
	for(;p;p>>=1,x=x*x%mod) if(p&1) ret=ret*x%mod;
	return ret;
}
ll sol=1,f[N];
int x[N];
ll F(int a, int b)
{
	return f[a]*pow(f[b],mod-2)%mod*pow(f[a-b],mod-2)%mod;
}
int main()
{
	int n,i,sum=0;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&x[i]),sum+=x[i];
	f[0]=1;
	for(i=1;i<N;i++) f[i]=f[i-1]*i%mod;
	for(i=n;i;i--)
	{
		sum--;x[i]--;
		sol=sol*F(sum,x[i])%mod;
		sum-=x[i];
	}
	printf("%lld\n",sol);
	return 0;
}