#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,k;
ll a[300005];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		a[i]+=a[i-1];
	}
	ll ans=a[n]*k;
	sort(a+1,a+n);
	for(int i=1;i<k;i++)ans-=a[i];
	printf("%I64d\n",ans);
	return 0;
}