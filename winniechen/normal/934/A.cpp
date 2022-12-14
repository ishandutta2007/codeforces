#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
#define N 105
long long a[N],b[N];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%I64d",&b[i]);
	}
	long long ans=1ll<<60;
	for(int i=1;i<=n;i++)
	{
		long long minx=-(1ll<<60);
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			for(int k=1;k<=m;k++)
			{
				minx=max(minx,a[j]*b[k]);	
			}
		}
		ans=min(ans,minx);
	}
	printf("%I64d\n",ans);
	return 0;
}