#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
long long ans;
int main()
{
	scanf("%d",&n);
	n=n*2;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	ans=((long long)(a[n/2]-a[1]))*(a[n]-a[n/2+1]);
	long long cmp=a[n]-a[1];
	for(int i=1;i<=n/2;i++)
		ans=min(ans,cmp*(a[i+n/2-1]-a[i]));
	printf("%lld",ans);
	return 0;
}