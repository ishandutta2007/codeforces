#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t;
ll n,m;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		ll ans=n*(n+1)/2;
		ll cnt=(n-m)/(m+1);
		ans-=cnt*(cnt+1)/2*(m+1-(n-m)%(m+1));
		ans-=(cnt+1)*(cnt+2)/2*((n-m)%(m+1));
		printf("%lld\n",ans);
	}
	return 0;
}