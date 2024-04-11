#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,a[100005],ls[100005],t[200005];
int lowbit(int x){return x & (-x);}
void insert1(int now,int val)
{
	while(now)
	{
		t[now] = max(t[now],val);
		now -= lowbit(now);
	}
}
void insert2(int now,int val)
{
	while(now)
	{
		t[now] = min(t[now],val);
		now -= lowbit(now);
	}
}
int ask1(int now)
{
	int re = 0;
	while(now <= n)
	{
		re = max(re,t[now]);
		now += lowbit(now);
	}
	return re;
}
int ask2(int now)
{
	int re = n + 1;
	while(now <= n)
	{
		re = min(re,t[now]);
		now += lowbit(now);
	}
	return re;
}
int main()
{
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
		scanf("%d",&a[i]),ls[i] = a[i];
	if(n == 1) {printf("%d\n",0); return 0;}
	sort(ls + 1, ls + n + 1);
	ls[0] = unique(ls + 1, ls + n + 1) - ls - 1;
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(ls + 1, ls + ls[0] + 1,a[i]) - ls;
	int ans = 0;
	insert1(a[1],1);
	for (int i = 2; i <= n; i++)
	{
		if(ask1(a[i] + 1) > 0)ans = max(ans,ls[a[i]]^ls[a[ask1(a[i] + 1)]]);
		insert1(a[i],i);
	}
	for (int i = 1; i <= n; i++)
		t[i] = n + 1;
	insert2(a[n],n);
	for (int i = n - 1; i >= 1; i--)
	{
		if(ask2(a[i] + 1) < n + 1)ans = max(ans,ls[a[i]]^ls[a[ask2(a[i] + 1)]]);
		insert2(a[i],i);
	}
	printf("%d\n",ans);
	return 0;
}