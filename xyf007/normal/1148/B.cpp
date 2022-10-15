#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
long long n,m,k,ta,tb,a[200001],b[200001];
void checkmax(long long &x,long long y)
{
	if(x<y)
	{
		x=y;
	}
}
int main()
{
	scanf("%lld%lld%lld%lld%lld",&n,&m,&ta,&tb,&k);
	if(k>=n||k>=m)
	{
		printf("-1");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&b[i]);
	}
	long long max=-1;
	for(int i=0;i<=k;i++)
	{
		int temp=a[i+1]+ta,pos=std::lower_bound(b+1,b+m+1,temp)-b;
		if(pos+k-i>m)
		{
			printf("-1");
			return 0;
		}
		checkmax(max,b[pos+k-i]+tb);
	}
	printf("%lld",max);
	return 0;
}