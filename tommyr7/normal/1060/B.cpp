#include <bits/stdc++.h>
using namespace std;
long long n;
int calc(long long n)
{
	int ans=0;
	while (n>0)
	{
		ans+=(int)(n%10);
		n/=10;
	}
	return ans;
}
int main()
{
	scanf("%lld",&n);
	int ans=calc(n);
	long long now=0,del=1,tot=0;
	while (now<=n)
	{
		now+=del;
		++tot;
		if (tot==9)
		{
			tot=0;
			del=10LL*del;
		}
		if (now<=n) ans=max(ans,calc(now)+calc(n-now));
	}
	printf("%d\n",ans);
	return 0;
}