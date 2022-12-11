#include <bits/stdc++.h>
#define Maxn 3007
using namespace std;
int n,m,now=0;
int pos[Maxn],val[Maxn],tot[Maxn];
priority_queue<int> s[Maxn],q;
long long check(int x)
{
	for (int i=2;i<=m;i++)
		while (!s[i].empty()) s[i].pop();
	memset(tot,0,sizeof(tot));
	while (!q.empty()) q.pop();
	for (int i=1;i<=n;i++)
		if (pos[i]!=1)
		{
			s[pos[i]].push(-val[i]);
			++tot[pos[i]];
		}
	long long res=0;
	int cnt=0;
	for (int i=2;i<=m;i++)
	{
		while (tot[i]>=x)
		{
			++cnt;
			--tot[i];
			res-=s[i].top();
			s[i].pop();
		}
	}
	for (int i=2;i<=m;i++)
	{
		while (!s[i].empty())
		{
			q.push(s[i].top());
			s[i].pop();
		}
	}
	while (now+cnt<x)
	{
		++cnt;
		res-=q.top();
		q.pop();
	}
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	int r;
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&pos[i],&val[i]);
		if (pos[i]==1) ++now;
	}
	r=now;
	long long ans=0;
	for (int i=1;i<=n;i++)
		ans+=val[i];
	for (int i=max(r,1);i<=n;i++)
		ans=min(ans,check(i));
	printf("%lld\n",ans);
	return 0;
}