#include <bits/stdc++.h>
#define Maxn 2000007
using namespace std;
int n;
int a[Maxn];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n*2;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+2*n+1);
	long long ans=1000000000000000000LL;
	ans=1LL*(a[n]-a[1])*(a[2*n]-a[n+1]);
	for (int i=2;i<=n;i++)
		ans=min(ans,1LL*(a[2*n]-a[1])*(a[i+n-1]-a[i]));
	printf("%lld\n",ans);
	return 0;
}