#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T,n;
ll a[35],k;
int has[65];
ll fastpow(ll a,ll p)
{
	ll ans=1;
	for(;p;p>>=1,a=a*a)if(p&1)ans=ans*a;
	return ans;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%I64d",&n,&k);
		memset(has,0,sizeof(has));
		for(int i=1;i<=n;++i)scanf("%I64d",&a[i]);
		int maxv=0;
		for(int i=1;i<=60;++i)
		{
			if(fastpow(k,i)<=fastpow(10,16))maxv=i;
			else break;
		}
		for(int i=1;i<=n;++i)
		{
			ll x=a[i];
			for(int j=maxv;j>=0;--j)
			{
				while(x>=fastpow(k,j))x-=fastpow(k,j),has[j]++;
			}
		}
		bool yes=1;
		for(int i=0;i<=maxv;++i)if(has[i]>1)yes=0;
		if(yes)puts("YES");
		else puts("NO");
	}
}