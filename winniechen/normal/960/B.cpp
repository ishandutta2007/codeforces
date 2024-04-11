#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;
#define N 1005
int a[N],b[N],k1,k2,n,c[N];
int main()
{
	scanf("%d%d%d",&n,&k1,&k2);
	k1+=k2;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		c[i]=abs(b[i]-a[i]);
	}
	while(k1--)
	{
		sort(c+1,c+n+1);
		c[n]=abs(c[n]-1);
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=(1ll*c[i]*c[i]);
	}
	printf("%I64d\n",ans);
	return 0;
}