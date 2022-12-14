#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define ll long long
ll n,k,l,r;
void ex_gcd(ll a,ll b,ll &x,ll &y)
{
	if(!b){x=1,y=0;return ;}
	ex_gcd(b,a%b,x,y);ll t=x;x=y;y=t-a/b*y;
}
int main()
{
	scanf("%lld%lld%lld%lld",&n,&l,&r,&k);
	if(l>r)r=n-l+r+1,l=1;
	else r=r-l+1,l=1;
	if(n<=1000000)
	{
		ll ans=-1;
		for(int bit=1;bit<=2;bit++)for(int lt=1;lt<=bit;lt++)
		{
			for(int i=n+bit-1;i<=n*2;i++)
			{
				ll t=k/i;ll y=k%i;
				if(r==n)
				{
					if((y+lt-1)%i==0)ans=max(i-n,ans);
					continue;
				}
				// printf("%lld\n",y);
				if(i-n-(y-r+bit-lt)>n-r||y-r>i-n||y-r+1<lt||y>(r-1)*2+lt)continue;
				ans=max(i-n,ans);
			}
		}
		printf("%lld\n",ans);
	}else
	{
		ll lim=k/n,ans=-1;
		for(int bit=1;bit<=2;bit++)for(int lt=1;lt<=bit;lt++)
		{
			if(k<r+lt-1)continue;
			if(k<=r*2-2+lt){ans=max(ans,k-r+bit-1+n-r);continue;}
			for(int i=1;i<=lim;i++)
			{
				ll y=k/i;ll x=k%i;
				if(x<r-1+lt)
				{
					ll t=(r-2+lt-x)/i+1;
					x+=t*i;y-=t;
				}
				if((y-x+lt-bit)-2*(n-r)>0)
				{
					ll t=((y-x+lt-bit)-2*(n-r)-1)/(i+1)+1;
					x+=t*i;y-=t;
				}
				if(x>y)continue;
				if(r==n)
				{
					if((y-x-bit+lt)%(i+1)==0)
					{
						ll t=(y-x-bit+lt)/(i+1);
						x+=t*i;y-=t;
					}
					if((!x&&lt==bit)||x+bit-lt==y)ans=max(ans,y-n);
					continue;
				}
				if(y>2*(n-1)+bit||(y<n-1+bit&&y!=0))continue;
				if(x>(r-1)*2+lt||(x<r-1+lt&&x!=0))continue;
				ans=max(y-n,ans);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}