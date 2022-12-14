#include <cstdio>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 300005
#define ll long long
ll f[N],ans,a[N],b[N],sum1[N],sum2[N],t1[N],t2[N],t3[N],t4[N],n;
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(ll i=n;i;i--)t2[i]=t2[i+1]+a[i]*(2ll*n-i),sum1[i]=sum1[i+1]+a[i],t1[i]+=t1[i+1]+a[i]*(i-1);
	for(ll i=1;i<=n;i++)scanf("%lld",&b[i]);
	for(ll i=n;i;i--)t4[i]=t4[i+1]+b[i]*(2ll*n-i),sum2[i]=sum2[i+1]+b[i],t3[i]+=t3[i+1]+b[i]*(i-1);
	f[0]=0;ans=t1[1]+t4[1];
	//prllf("%lld %lld %lld %lld\n",t1[1],t2[1],t3[1],t4[1]);
	for(ll i=1;i<=n;i++)
	{
		if(i&1)
		{
			f[i]=f[i-1]+a[i]*((i<<1)-2)+b[i]*((i<<1)-1);
			ans=max(ans,f[i]+i*(sum1[i+1]+sum2[i+1])+t2[i+1]+t3[i+1]);
		}
		else
		{
			f[i]=f[i-1]+a[i]*((i<<1)-1)+b[i]*((i<<1)-2);
			ans=max(ans,f[i]+i*(sum1[i+1]+sum2[i+1])+t1[i+1]+t4[i+1]);
		}
	}printf("%lld\n",ans);return 0;
}