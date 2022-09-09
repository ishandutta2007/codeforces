#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll a,b,x,y;
	scanf("%lld %lld %lld %lld",&a,&b,&x,&y);
	ll g=__gcd(x,y);
	x/=g;y/=g;
	ll top=1e18+5,bot=1,mid,ans=0;
	while(top>=bot)
	{
		mid=top+bot>>1;
		if(x<(a+mid)/mid && y<(b+mid)/mid) ans=mid,bot=mid+1;
		else top=mid-1;
	}
	printf("%lld\n",ans);
	return 0;
}