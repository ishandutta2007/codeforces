#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;
#define N 100005
int a[N],n,maxx,minn,num[3];
long long sum;
int main()
{
	minn=N,maxx=-N;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
	}
	if(maxx<=minn+1)
	{
		printf("%d\n",n);
		for(int i=1;i<n;i++)
		{
			printf("%d ",a[i]);
		}
		printf("%d\n",a[n]);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==minn)num[0]++;
		else if(a[i]==maxx)num[2]++;
		else num[1]++;
	}
	int t=(min(num[0],num[2])*2);
	if(num[1]<=t)
	{
		printf("%d\n",n-t);
		if(t+num[1]!=n)
		{
			for(int i=1;i<=t+num[1];i++)
			{
				printf("%d ",minn+1);
			}
		}else
		{
			for(int i=1;i<n;i++)
			{
				printf("%d ",minn+1);
			}
			printf("%d\n",minn+1);
			return 0;
		}
		if(num[0]<num[2])
		{
			for(int i=1;i<n-t-num[1];i++)
			{
				printf("%d ",maxx);
			}
			printf("%d\n",maxx);
		}else
		{
			for(int i=1;i<n-t-num[1];i++)
			{
				printf("%d ",minn);
			}
			printf("%d\n",minn);
		}
	}else
	{
		if(num[1]&1)
		{
			printf("%d\n",n-num[1]+1);
			printf("%d ",minn+1);
			n--;
		}else
			printf("%d\n",n-num[1]);
		for(int i=1;i<=(num[1]>>1);i++)
		{
			printf("%d %d ",minn,maxx);
		}
		for(int i=1;i<=num[0];i++)
		{
			printf("%d ",minn);
		}
		for(int i=1;i<num[2];i++)
		{
			printf("%d ",maxx);
		}
		printf("%d\n",maxx);
	}
	return 0;
}