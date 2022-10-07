#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[2005];
int n,edgenum,head[1005],d[1005];
queue<int>q;
bool flag[1005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
		d[u]++,d[v]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(d[i]==1)
		{
			q.push(i);
		}
	}
	for(int k=1;k<=n/2;k++)
	{
		int x=q.front();
		q.pop();
		int y=q.front();
		q.pop();
		printf("? %d %d\n",x,y);
		fflush(stdout);
		int u;
		scanf("%d",&u);
		if(u==x)
		{
			printf("! %d\n",x);
			return 0;
		}
		if(u==y)
		{
			printf("! %d\n",y);
			return 0;
		}
		flag[x]=1;
		for(int hd=head[x];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(!flag[to])
			{
				d[to]--;
				if(d[to]==1)
				{
					q.push(to);
				}
			}
		}
		flag[y]=1;
		for(int hd=head[y];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(!flag[to])
			{
				d[to]--;
				if(d[to]==1)
				{
					q.push(to);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!flag[i])
		{
			printf("! %d\n",i);
			return 0;
		}
	}
	return 0;
}