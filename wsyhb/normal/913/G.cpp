#include<bits/stdc++.h>
using namespace std;
inline int count_bits(long long x)
{
	int cnt=0;
	while(x>0)
		x/=10,++cnt;
	return cnt;
}
inline long long qpow(long long a,long long n,long long mod)
{
	long long res=1;
	while(n>0)
	{
		if(n&1)
			res=(__int128)res*a%mod;
		a=(__int128)a*a%mod;
		n>>=1;
	}
	return res;
}
int main()
{
	const int m=6;
	const int Pow=1e6;
	const int p=5;
	const int g=2;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long a;
		scanf("%lld",&a);
		int n=count_bits(a);
		long long b=(-a*Pow)&((1ll<<(n+m))-1);
		if(b%5==0)
			b|=(1ll<<(n+m));
		long long x=a*Pow+b;
		long long y=x>>(n+m);
		long long now=1;
		long long d=-1,goal=y%p;
		for(int i=0;i<p-1;++i)
		{
			if(now==goal)
			{
				d=i;
				break;
			}
			now*=g,now-=now>=p?p:0;
		}
		assert(d!=-1);
		long long phi=p-1,mod=p;
		for(int i=1;i<n+m;++i)
		{
			mod*=p;
			long long now=qpow(g,d,mod),delta=qpow(g,phi,mod),goal=y%mod;
			while(now!=goal)
			{
				now=(__int128)now*delta%mod;
				d+=phi;
			}
			phi*=p,d%=phi;
		}
		printf("%lld\n",d+n+m);
	}
	return 0;
}