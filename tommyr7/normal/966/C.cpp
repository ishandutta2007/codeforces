#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int n;
long long a[Maxn];
priority_queue<long long> s[Maxn];
int cnt[Maxn];
long long ans[Maxn];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++)
	{
		int now=0;
		for (int k=0;k<60;k++)
			if (a[i]&(1LL<<k)) now=k;
		s[now].push(-a[i]);
		++cnt[now];
	}
	long long now=0;
	for (int i=1;i<=n;i++)
	{
		bool flag=false;
		for (int k=0;k<60;k++)
			if ((now&(1LL<<k))==0&&cnt[k]>0)
			{
				flag=true;
				--cnt[k];
				ans[i]=-s[k].top();
				now^=ans[i];
				s[k].pop();
				break;
			}
		if (!flag)
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	for (int i=1;i<=n;i++)
		printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}