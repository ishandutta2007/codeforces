#include <stdio.h>
#include <set>
using namespace std;
#define ll long long
const int N=100050;
ll t[N],a[N],sol[N];
multiset<ll> snow;
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(i=1;i<=n;i++) scanf("%lld",&t[i]),t[i]+=t[i-1];
	ll sum=0;
	for(i=1;i<=n;i++)
	{
		sum+=a[i]+t[i-1];
		snow.insert(a[i]+t[i-1]);
		while(snow.size() && *snow.begin()<=t[i])
		{
			sol[i]+=*snow.begin()-t[i-1];
			snow.erase(snow.begin());
		}
		sol[i]+=(t[i]-t[i-1])*snow.size();
		printf("%lld ",sol[i]);
	}
	printf("\n");
	return 0;
}