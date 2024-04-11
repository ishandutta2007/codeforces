#include <bits/stdc++.h>
using namespace std;
long long n,k,m;
long long ans;
int d;
int main()
{
	scanf("%lld%lld%lld%d",&n,&k,&m,&d);
	ans=1LL*m*((n/m+k-1)/k);
	for (int i=1;i<=d;i++)
	{
		long long t=1LL*k*i-k+1;
		if (t>n) break;
		if (n/t>m) continue;
		ans=max(ans,1LL*i*(n/t));
	}
	printf("%lld\n",ans);
	return 0;
}