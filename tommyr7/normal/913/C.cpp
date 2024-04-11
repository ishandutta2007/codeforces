#include <bits/stdc++.h>
#define Maxn 37
using namespace std;
long long f[Maxn];
int n,L;
int main()
{
	scanf("%d%d",&n,&L);
	for (int i=1;i<=n;i++)
		scanf("%lld",&f[i]);
	for (int i=n+1;i<=30;i++)
		f[i]=1000000000000000000LL;
	for (int i=2;i<=30;i++)
		f[i]=min(f[i],2LL*f[i-1]);
	long long ans=0;
	for (int i=1;i<=30;i++)
	{
		ans=min(ans,f[i]);
		if (L&(1<<(i-1))) ans+=f[i];
	}
	printf("%lld\n",ans);
	return 0;
}