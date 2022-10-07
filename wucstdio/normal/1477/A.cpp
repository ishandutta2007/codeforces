#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t,n;
ll k,a[200005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&k);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		ll d=0;
		for(int i=2;i<=n;i++)d=__gcd(d,abs(a[i]-a[1]));
		if((k-a[1])%d==0)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}