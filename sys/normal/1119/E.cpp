#include <bits/stdc++.h>
using namespace std;
const int Maxn=300005;
int n;
long long las,ans,f[Maxn],a[Maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		f[i]=min(las,a[i]/2);
		las-=f[i];
		a[i]-=f[i]*2;
		ans+=f[i]+a[i]/3;
		las+=a[i]%3;
	}
	printf("%lld",ans);
	return 0;
}