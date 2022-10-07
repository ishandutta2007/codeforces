#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll n,p,w,d;
int main()
{
	scanf("%lld%lld%lld%lld",&n,&p,&w,&d);
	swap(w,d);
	for(ll x=0;x<=d&&w*x<=p;x++)
	{
		ll rest=p-w*x;
		if(rest%d==0)
		{
			ll y=rest/d;
			if(x+y<=n)
			{
				printf("%lld %lld %lld\n",y,x,n-x-y);
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}