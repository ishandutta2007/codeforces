#include <bits/stdc++.h>
#define Maxn 27
using namespace std;
int n,m;
pair<int,int> q1[Maxn],q2[Maxn];
bool vis[10],flag[10];
int calc(int x,int y)
{
	if (q1[x].first==q2[y].first&&q1[x].second==q2[y].second) return 0;
	if (q1[x].first==q2[y].second&&q1[x].second==q2[y].first) return 0;
	if (q1[x].first==q2[y].first) return q1[x].first;
	if (q1[x].first==q2[y].second) return q1[x].first;
	if (q1[x].second==q2[y].first) return q1[x].second;
	if (q1[x].second==q2[y].second) return q1[x].second;
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&q1[i].first,&q1[i].second);
	for (int i=1;i<=m;i++)
		scanf("%d%d",&q2[i].first,&q2[i].second);
	int ans=0,res=0;
	for (int i=1;i<=n;i++)
	{
		memset(vis,false,sizeof(vis));
		int now=0;
		for (int j=1;j<=m;j++)
		{
			int t=calc(i,j);
			if (t>0)
			{
				if (!vis[t])
				{
					vis[t]=true;
					++now;
				}
				if (!flag[t])
				{
					flag[t]=true;
					res=t;
					++ans;
				}
			}
		}
		if (now>1)
		{
			printf("%d\n",-1);
			return 0;
		}
	}
	memset(flag,false,sizeof(flag));
	ans=0,res=0;
	for (int i=1;i<=m;i++)
	{
		memset(vis,false,sizeof(vis));
		int now=0;
		for (int j=1;j<=n;j++)
		{
			int t=calc(j,i);
			if (t>0)
			{
				if (!vis[t])
				{
					vis[t]=true;
					++now;
				}
				if (!flag[t])
				{
					flag[t]=true;
					res=t;
					++ans;
				}
			}
		}
		if (now>1)
		{
			printf("%d\n",-1);
			return 0;
		}
	}
	if (ans>1) printf("%d\n",0); else printf("%d\n",res);
	return 0;
}