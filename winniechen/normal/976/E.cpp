#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
#define ll long long
#define N 200005
struct node
{
	ll h,d;
	int idx;
}t[N];
int n;
int a;
int b;
bool cmp(const node &a,const node &b)
{
	return (a.h-a.d)>(b.h-b.d);
}
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d %I64d",&t[i].h,&t[i].d);
		t[i].idx=i;
	}
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=t[i].d;
	}
	if(!b)
	{
		printf("%I64d\n",sum);
		return 0;
	}
	sort(t+1,t+n+1,cmp);
	for(int i=1;i<=min(n,b);i++)
	{
		sum+=max(t[i].h-t[i].d,0ll);
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i<=b)
		{
			ans=max(sum+max((t[i].h<<a)-t[i].d,0ll)-max(t[i].h-t[i].d,0ll),ans);
		}else
		{
			ans=max(max((t[i].h<<a)-t[i].d,0ll)-max(t[b].h-t[b].d,0ll)+sum,ans);
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
/*
2 1 1
10 12
6 1
 */