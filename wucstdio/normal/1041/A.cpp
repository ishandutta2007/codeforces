#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll n,a[1005];
int main()
{
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	ll ans=0;
	for(int i=2;i<=n;i++)
	  ans+=a[i]-a[i-1]-1;
	printf("%I64d\n",ans);
	return 0;
}