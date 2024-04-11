#include <stdio.h>
#define ll long long
const ll inf=1e18;
int main()
{
	ll n,x,sol=inf,y;
	int taj,b;
	scanf("%lld %i",&n,&b);
	for(int i=1;i<=b;i++)
	{
		scanf("%lld",&x);
		ll ans=n%x;
		if(ans<sol) sol=ans,taj=i,y=n/x;
	}
	printf("%i %lld\n",taj,y);
	return 0;
}