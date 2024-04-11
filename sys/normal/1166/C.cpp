#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
int n,a[Maxn];
long long ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),a[i]=abs(a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)
		ans+=upper_bound(a+i,a+1+n,2*a[i])-a-i-1;
	printf("%lld",ans);
	return 0;
}