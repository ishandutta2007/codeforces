#include <bits/stdc++.h>
#define Maxn 400007
#define eps 1e-15
using namespace std;
int n;
long long x,s;
long long w[Maxn],h[Maxn],c[Maxn];
map<long long,long long>cnt1,cnt2;
long long gcd(long long a,long long b)
{
	if (a==0) return b;
	if (b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&w[i],&h[i],&c[i]);
		x=gcd(x,c[i]);
	}
	for (int i=1;i<=n;i++)
	{
		c[i]/=x;
		s+=c[i];
		cnt1[w[i]]+=c[i];
		cnt2[h[i]]+=c[i];
	}
	for (int i=1;i<=n;i++)
	{
		double t1=(double)cnt1[w[i]]/s;
		double t2=(double)c[i]/cnt2[h[i]];
		if (!(t1-t2<eps&&t1-t2>-eps))
		{
			printf("%d\n",0);
			return 0;
		}
	}
	long long ans=0;
	for (int i=1;1LL*i*i<=x;i++)
		if (x%i==0)
		{
			++ans;
			if (1LL*i*i!=x) ++ans;
		}
	printf("%lld\n",ans);
	return 0;
}