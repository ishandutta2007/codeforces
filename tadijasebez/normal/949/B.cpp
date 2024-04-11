#include <stdio.h>
#define ll long long
int main()
{
	ll n,x;
	int q,i;
	scanf("%lld %i",&n,&q);
	while(q--)
	{
		scanf("%lld",&x);
		while(!(x&1))
		{
			x+=(n-(x>>1));
		}
		printf("%lld\n",(x+1)/2);
	}
	return 0;
}