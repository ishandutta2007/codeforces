#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
long long n,h,a[10001],temp[10001];
bool check(long long x)
{
	long long hh=h;
	memset(temp,0,sizeof(temp));
	for(int i=1;i<=x;i++)
	{
		temp[i]=a[i];
	}
	std::sort(temp+1,temp+x+1);
	for(int i=x;i>=1;i-=2)
	{
		hh-=temp[i];
	}
	return hh>=0;
}
int main()
{
	scanf("%lld%lld",&n,&h);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	long long l=0,r=n,best=-1;
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
	printf("%lld",best);
	return 0;
}