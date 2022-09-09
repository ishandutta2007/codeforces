#include <stdio.h>
#define ll long long
const int N=100050;
const int mod=1e9+7;
int pow(int x, ll k)
{
	int ret=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;
	return ret;
}
ll a[N];
int main()
{
	int n,i,p,q,m=1;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]),m&=a[i]&1;
	q=2;for(i=1;i<=n;i++) q=pow(q,a[i]);
	int f;if(m) f=-1;else f=1;
	q=(ll)q*pow(2,mod-2)%mod;
	p=(ll)(q+f)*pow(3,mod-2)%mod;
	printf("%i/%i\n",p,q);
	return 0;
}