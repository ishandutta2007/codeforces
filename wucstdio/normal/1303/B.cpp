#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t;
ll n,a,b;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&a,&b);
		ll ned=(n+1)/2;
		ll t1=(ned-1)/a*(a+b)+(ned-(ned-1)/a*a);
		printf("%lld\n",max(t1,n));
	}
	return 0;
}