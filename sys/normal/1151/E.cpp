#include <bits/stdc++.h>
using namespace std;
const int Maxn=100005;
int a[Maxn],n;
long long ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		ans+=a[i]*(long long)(n-a[i]+1);
	for(int i=1;i<n;i++)
		ans-=min(a[i],a[i+1])*(long long)(n-max(a[i],a[i+1])+1);
	printf("%lld",ans);
	return 0;
}