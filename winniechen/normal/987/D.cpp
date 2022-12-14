#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <cstdlib>
using namespace std;
#define N 100005
struct node
{
	int to,next,val;
}e[N<<1];
int head[N],cnt,dis[N],vis[N],a[N],n,m,k,s;
priority_queue <int>ans[N];
void add(int x,int y,int z)
{
	e[cnt].to=y;
	e[cnt].next=head[x];
	e[cnt].val=z;
	head[x]=cnt++;
}
void spfa(int c)
{
	memset(dis,0x3f,sizeof(dis));
	queue <int>q;
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++)
	{
		if(a[i]==c)q.push(i),dis[i]=0,vis[i]=1;
	}
	int num=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();vis[x]=0;
		for(int i=head[x];i!=-1;i=e[i].next)
		{
			int to1=e[i].to;
			if(dis[to1]>dis[x]+e[i].val)
			{
				dis[to1]=dis[x]+e[i].val;
				if(!vis[to1])
				{
					vis[to1]=1;
					q.push(to1);
				}
			}
		}
	}
	if(c<=s)
	{
		for(int i=1;i<=n;i++)
		{
			ans[i].push(dis[i]);
		}
	}else
	{
		for(int i=1;i<=n;i++)
		{
			if(ans[i].top()>dis[i])
			{
				ans[i].pop();
				ans[i].push(dis[i]);
			}
		}
	}
	return ;
}
int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d%d%d%d",&n,&m,&k,&s);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y,1);add(y,x,1);
	}
	for(int i=1;i<=k;i++)spfa(i);
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		for(int j=1;j<=s;j++)
		{
			sum+=ans[i].top();ans[i].pop();
		}
		printf("%d ",sum);
	}
	puts("");
	return 0;
}