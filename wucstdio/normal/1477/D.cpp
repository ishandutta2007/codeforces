#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#include<queue>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[1000005];
int t,n,m,edgenum,head[500005],d[500005],tmp[500005],top,pa[500005],cur,p[500005],q[500005];
bool flag[500005];
set<pair<int,int> >s;
set<int>node;
queue<int>qq;
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to);
	}
	p[node]=++cur;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		if(!flag[to])p[to]=++cur;
	}
	if(cur==p[node])
	{
		cur--;
		return;
	}
	int curr=p[node]-1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		if(!flag[to])q[to]=++curr,flag[to]=1;
	}
	q[node]=++curr;
	flag[node]=1;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		edgenum=0;
		for(int i=1;i<=n;i++)head[i]=d[i]=pa[i]=flag[i]=0;
		s.clear();
		node.clear();
		for(int i=1;i<=n;i++)node.insert(i);
		while(m--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			s.insert(make_pair(u,v));
			s.insert(make_pair(v,u));
		}
		for(int st=1;st<=n;st++)
		{
			if(flag[st])continue;
			qq.push(st);
			flag[st]=1;
			node.erase(st);
			while(!qq.empty())
			{
				int x=qq.front();
				qq.pop();
				for(auto i:node)
				{
					if(s.find(make_pair(i,x))!=s.end())continue;
					tmp[++top]=i;
					qq.push(i);
					flag[i]=1;
					add(x,i);
					add(i,x);
				}
				while(top)node.erase(tmp[top--]);
			}
		}
		for(int i=1;i<=n;i++)flag[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(!flag[i])dfs(i);
			if(!flag[i])
			{
				if(!head[i])
				{
					p[i]=q[i]=++cur;
					continue;
				}
				q[i]=cur;
				p[i]=++cur;
				for(int hd=head[i];hd;hd=e[hd].nxt)
				{
					int to=e[hd].to;
					if(q[to]==cur-1)
					{
						q[to]=cur;
						break;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)printf("%d ",p[i]);
		printf("\n");
		for(int i=1;i<=n;i++)printf("%d ",q[i]);
		printf("\n");
		cur=0;
	}
	return 0;
}