#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,a[200005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int d=0;
	for(int i=1;i<n;i++)d=__gcd(d,a[n]-a[i]);
	ll ans=0;
	for(int i=1;i<n;i++)ans+=(a[n]-a[i])/d;
	printf("%lld %d\n",ans,d);
	return 0;
}