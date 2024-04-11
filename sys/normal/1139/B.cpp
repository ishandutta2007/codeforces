#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
int n,a[Maxn],now;
long long ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	now=0x3f3f3f3f;
	for(int i=n;i>=1;i--)
		ans+=min(a[i],now),now=min(a[i],now)==0?0:min(a[i],now)-1;
	printf("%lld",ans);
	return 0;
}