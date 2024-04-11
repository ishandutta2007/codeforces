#include <bits/stdc++.h>
using namespace std;
const int Maxn=1000005,p=998244353;
long long fac[Maxn],inv[Maxn];
int n;
long long fast_pow(long long x,long long y)
{
	long long ans=1,now=x;
	while(y)
	{
		if(y&1) ans=(ans*now)%p;
		now=(now*now)%p;
		y>>=1;
	}
	return ans;
}
void init(void)
{
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%p;
	inv[n]=fast_pow(fac[n],p-2);
	for(int i=n-1;i>=0;i--)
		inv[i]=inv[i+1]*(i+1)%p;
}
long long ans;
int main()
{
	scanf("%d",&n);
	init();
	for(int i=0;i<=n;i++)
		ans=(ans+fac[n]-fac[n]*inv[i])%p;
	ans=(((ans+1)%p)+p)%p;
	printf("%d",ans);
	return 0;
}