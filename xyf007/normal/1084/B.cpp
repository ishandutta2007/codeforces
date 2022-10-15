#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long n,s,a[1001];
bool check(long long x)
{
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>x)
		{
			sum+=a[i]-x;
		}
	}
	return sum>=s;
}
int main()
{
	scanf("%lld%lld",&n,&s);
	long long sum=0,mi=2e9;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]<mi)
		{
			mi=a[i];
		}
		sum+=a[i];
	}
	if(sum<s)
	{
		printf("-1");
		return 0;
	}
	long long l=0,r=2e9,best=-1;
	while(l<=r)
	{
		long long mid=(l+r)>>1;
		if(check(mid))
		{
			l=mid+1;
			best=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	printf("%lld",min(mi,best));
	return 0;
}
//d