#include <stdio.h>
#define ll long long
bool Try(ll &x, ll &y, ll a, ll b, ll n)
{
	x=0;
	y=0;
	ll tmp=n%a;
	x=n/a;
	for(int i=0;i<10000000;i++)
	{
		if(tmp%b==0)
		{
			y=tmp/b;
			return 1;
		}
		tmp+=a;
		x--;
		if(x<0) return 0;
	}
	return 0;
}
int main()
{
	ll n,a,b,x,y;
	scanf("%lld %lld %lld",&n,&a,&b);
	if(Try(x,y,a,b,n)) printf("YES\n%lld %lld\n",x,y);
	else if(Try(y,x,b,a,n)) printf("YES\n%lld %lld\n",x,y);
	else printf("NO\n");
	return 0;
}