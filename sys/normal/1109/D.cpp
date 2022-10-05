#include <bits/stdc++.h>
using namespace std;
const int p=1e9+7;
const int Maxn=1000005;
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
long long fac[Maxn],inv[Maxn],ans;
int n,m;
long long C(int x,int y)
{
	if(x<y) return 0;
	return fac[x]*inv[y]%p*inv[x-y]%p;
}
void init(void)
{
	fac[0]=inv[0]=1;
	for(int i=1;i<=max(n,m)+2;i++)
	{
		fac[i]=(fac[i-1]*i)%p;
		inv[i]=fast_pow(fac[i],p-2);
	}
}
int k;
int main()
{
	scanf("%d%d",&n,&m);
	init();
	for(int i=0;i<=n-2;i++)
	{
		k=n-i-1;
		long long tmp=C(m-1,i)*C(n-2,i)%p*fac[i]%p;
		tmp=tmp*fast_pow(m,n-i-2)%p;
		if(k>=2)
			tmp=tmp*fast_pow(n,k-2)%p*(i+2)%p;
		ans=(ans+tmp)%p;
	}
	cout<<ans;
}