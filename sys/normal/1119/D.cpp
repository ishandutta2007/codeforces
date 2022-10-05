#include <bits/stdc++.h>
using namespace std;
const int Maxn=100005;
int n,q;
long long a[Maxn],sum[Maxn],diff[Maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	scanf("%d",&q);
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)
		diff[i]=a[i+1]-a[i];
	sort(diff+1,diff+n);
	for(int i=1;i<n;i++)
		sum[i]=sum[i-1]+diff[i];
	for(int i=1;i<=q;i++)
	{
		long long l,r;
		scanf("%lld%lld",&l,&r);
		long long d=r-l+1;
		int pos=lower_bound(diff+1,diff+n,d)-diff;
		printf("%lld ",(a[n]+d-a[1])-(sum[n-1]-sum[pos-1]-(n-pos)*d));
	}
	return 0;
}