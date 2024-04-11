#include <bits/stdc++.h>
using namespace std;
int n,l[100005],r[100005];
long long ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&l[i],&r[i]);
	sort(l+1,l+1+n);
	sort(r+1,r+1+n);
	for(int i=1;i<=n;i++)
		ans+=max(l[i],r[i]);
	ans+=n;
	printf("%lld",ans);
	return 0;
}