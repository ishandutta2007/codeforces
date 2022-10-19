#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,m,d[N],in[N],c[N],a[N],ans[N],fl;
vector<pair<int,int>>e[N],r[N],g[N];
queue<int>q;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].emplace_back(v,i);
		r[v].emplace_back(u,i);
	}
	a[1]=1,a[n]=2;
	for(int i=1;i<=n;i++)
		if(a[i]&1)
			for(int j=0;j<e[i].size();j++)
				a[e[i][j].first]|=1;
	for(int i=n;i>=1;i--)
		if(a[i]&2)
			for(int j=0;j<r[i].size();j++)
				a[r[i][j].first]|=2;
	for(int u=1;u<=n;u++)
	{
		if(a[u]!=3)
			continue;
		for(int i=0;i<e[u].size();i++)
		{
			int v=e[u][i].first;
			if(a[v]!=3)
				continue;
			g[u].emplace_back(v,2);
			g[v].emplace_back(u,-1);
		}
	}
	for(int i=1;i<=n;i++)
		d[i]=1e9;
	d[1]=0,c[1]++,in[1]=1;
	q.push(1);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		in[u]=0;
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i].first,dis=g[u][i].second;
			if(d[v]>d[u]+dis)
			{
				d[v]=d[u]+dis;
				if(!in[v])
				{
					q.push(v);
					in[v]=1;
					c[v]++;
					if(c[v]>n)
					{
						fl=1;
						break;
					}
				}
			}
		}
		if(fl)
			break;
	}
	if(fl)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int u=1;u<=n;u++)
	{
		for(int i=0;i<e[u].size();i++)
		{
			int v=e[u][i].first,id=e[u][i].second;
			if(a[u]!=3||a[v]!=3)
				ans[id]=1;
			else
				ans[id]=d[v]-d[u];
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}