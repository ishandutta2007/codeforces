#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll calc(ll x)
{
	ll ans=0;
	for(ll i=1,j=1;i<=x;i*=10,j++)
	{
		if(i*10<=x)ans+=j*i*9;
		else ans+=(x-i+1)*j;
		if(ans>1e18)return 1e18;
	}
	return ans;
}
int q;
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		ll n;
		scanf("%lld",&n);
		ll i=1,f=1;
		while(n>f) 
		{
			n-=f;
			i++;
			ll v=i;
			while(v)f++,v/=10;
		}
		ll l=1,r=i;
		while(l<=r)
		{
			ll mid=(l+r)/2;
			if(calc(mid)<n)l=mid+1;
			else r=mid-1;
		}
		n-=calc(r);
		ll v=l,x=0;
		while(v)x++,v/=10;
		n=x-n;
		for(int i=1;i<=n;i++)l/=10;
		printf("%lld\n",l%10);
	}
	return 0;
}