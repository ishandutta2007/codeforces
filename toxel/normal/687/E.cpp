#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#define N 5010
using namespace std;
typedef struct edge
{
	int next,to;
};
typedef struct point
{
	int first,value,dfs,early,visited,type;
	bool instack;
};
edge edg[N];
point poi[N];
bool out[N];
int e=0,index=0,type=0,ans[N],n,m;
queue<int>q;
stack<int>s; 
void addedge(int u,int v)
{
	edg[++e].to=v;
	edg[e].next=poi[u].first;
	poi[u].first=e;
}
void tarjan(int i)
{
	poi[i].visited = true;
	poi[i].dfs = poi[i].early = ++index;
	poi[i].value = 1;
	s.push(i);
	poi[i].instack = true;
	for (int j = poi[i].first; j; j = edg[j].next)
	{
		if (!poi[edg[j].to].visited)
			tarjan(edg[j].to);
		if (poi[edg[j].to].instack)
			poi[i].early = min(poi[i].early, poi[edg[j].to].early);
	}
	if (poi[i].dfs == poi[i].early)
	{
		type++;
		while (s.top() != i)
		{
			poi[s.top()].type = type;
			poi[s.top()].instack = false;
			s.pop();
		}
		poi[s.top()].type = type;
		poi[s.top()].instack = false;
		s.pop();
	}
}
void bfs(int i)
{
	int j;
	for (j=1;j<=n;j++)
		poi[j].value=0;
	while (!q.empty())
		q.pop();
	poi[i].value=1;
	q.push(i);
	while (!q.empty())
	{
		for (i=q.front(),q.pop(),j=poi[i].first;j;j=edg[j].next)
			if (poi[edg[j].to].type==poi[i].type)
			{
				if (!poi[edg[j].to].value)
				{
					poi[edg[j].to].value=poi[i].value+1;
					q.push(edg[j].to);
				}
				else
					ans[poi[i].type]=min(ans[poi[i].type],poi[edg[j].to].value+poi[i].value-1);
			}
	}
}
int main()
{
	int i,u,v,j;
	memset(out,false,sizeof(out));
	scanf("%d%d",&n,&m);
	for (i=0;i<N;i++)
		ans[i]=N;
	for (i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	for (i=1;i<=n;i++)
		poi[i].visited=false;
	for (i=1;i<=n;i++)
		if (!poi[i].visited)
			tarjan(i);
	for (i=1;i<n;i++)
		if (!out[poi[i].type])
			for (j=poi[i].first;j;j=edg[j].next)
				if (poi[i].type!=poi[edg[j].to].type)
				{
					out[poi[i].type]=true;
					break;
				}
	for (i=1;i<n;i++)
		if (!out[poi[i].type])
			bfs(i);
	ans[0]=n;
	for (i=1;i<=type;i++)
		if (ans[i]<N)
			ans[0]+=998*ans[i]+1;
	printf("%d\n",ans[0]);
	return 0;
}