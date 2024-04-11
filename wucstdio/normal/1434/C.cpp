#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t;
ll a,b,c,d;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(a>b*c)
		{
			printf("-1\n");
			continue;
		}
		ll v=b*d;
		ll n=min(c/d,a/v);
		printf("%lld\n",a*(n+1)-(n+1)*n/2*v);
	}
	return 0;
}