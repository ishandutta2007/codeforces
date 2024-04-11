#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t;
ll a,b;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&a,&b);
		a=__gcd(a,b);
		b/=a;
		ll ans=1;
		for(ll i=2;i*i<=b;i++)
		{
			if(b%i==0)
			{
				while(b%i==0)
				{
					ans*=i;
					b/=i;
				}
				ans/=i;
				ans*=i-1;
			}
		}
		if(b!=1)ans*=b-1;
		printf("%lld\n",ans);
	}
	return 0;
}