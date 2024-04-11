#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <cstdlib>
using namespace std;
#define N 105
#define ll long long
ll a[N],n,d,ans,cnt,t;
int main()
{
	scanf("%lld%lld",&n,&d);
	t=0;
	for(int i=0;(1<<i)<=n;i++)
	{
		if((1<<i)&n)
		{
			ans+=i+1;
			for(int j=1;j<=i;j++)
			{
				a[cnt+j]=t+d;
			}
			t+=d+1;
			a[cnt+i+1]=t+d;
			cnt+=i+1;
			t+=d+1;
		}
	}
	printf("%lld\n",ans);
	for(int i=1;i<ans;i++)
	{
		printf("%lld ",a[i]);
	}
	printf("%lld\n",a[ans]);
	return 0;
}