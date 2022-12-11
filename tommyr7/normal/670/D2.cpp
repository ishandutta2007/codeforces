#include <bits/stdc++.h>
using namespace std;
int n,k;
long long ans;
int a[100007],b[100007];
bool check(long long x)
{
	long long r=0;
	for (int i=1;i<=n;i++)
	{
		r+=max((long long)0,(1LL*a[i]*x-b[i]));
		if (r>k) return false;
	}
	return true;
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	long long lx=0,rx=2000000007;
	while (rx-lx>1)
	{
		int mid=(lx+rx)/2;
		if (check(mid)) lx=mid; else rx=mid;
	}
	if (check(rx)) ans=rx; else ans=lx;
	printf("%I64d\n",ans);
	return 0;
}