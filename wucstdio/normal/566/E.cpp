#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[2005];
int n,edgenum,head[1005],d[1005];
bool x[1005][1005];
bitset<1005>s[1005],a,flag;
bool vis[1005];
void add(int u,int v)
{
	x[u][v]=1;
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int main()
{
	scanf("%d",&n);
	if(n<=2)
	{
		printf("1 2\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		while(k--)
		{
			int x;
			scanf("%d",&x);
			s[i][x]=1;
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	{
		a=s[i]&s[j];
		if(a.count()==2)
		{
			int u=0,v=0;
			for(int k=1;k<=n;k++)
			{
				if(a[k])
				{
					if(!u)u=k;
					else v=k;
				}
			}
			if(x[u][v])continue;
			add(u,v);
			add(v,u);
			flag[u]=flag[v]=1;
			d[u]++,d[v]++;
		}
	}
	if(edgenum==0)
	{
		for(int i=2;i<=n;i++)printf("1 %d\n",i);
		return 0;
	}
	if(edgenum==2)
	{
		int u=0,v=0;
		for(int i=1;i<=n;i++)
		{
			if(flag[i])
			{
				if(!u)u=i;
				else v=i;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if((int)s[i].count()==n)continue;
			printf("%d %d\n",u,v);
			for(int j=1;j<=n;j++)
			{
				if(j==u||j==v)continue;
				if(s[i][j])printf("%d %d\n",u,j);
				else printf("%d %d\n",v,j);
			}
			return 0;
		}
	}
	int num=edgenum/2+1;
	while(num>2)
	{
		for(int i=1;i<=n;i++)
		{
			if(vis[i])continue;
			if((s[i]&flag).count()==2)
			{
				vis[i]=1;
				int u=0;
				for(int j=1;j<=n;j++)
				{
					if(s[i][j]&&d[j]==1)
					{
						u=j;
						break;
					}
				}
				d[u]=0;
				flag[u]=0;
				for(int hd=head[u];hd;hd=e[hd].nxt)
				{
					int to=e[hd].to;
					if(d[to])d[to]--;
				}
				for(int j=1;j<=n;j++)
				{
					if(s[i][j]&&!head[j])
					{
						add(u,j);
						add(j,u);
					}
				}
				num--;
				break;
			}
		}
	}
	int u=0,v=0;
	for(int i=1;i<=n;i++)
	{
		if(flag[i])
		{
			if(!u)u=i;
			else v=i;
		}
	}
	if(!e[head[u]].nxt)swap(u,v);
	for(int i=1;i<=n;i++)
	{
		if(!s[i][u]||!s[i][v])continue;
		bool f1=0,f2=0;
		for(int j=1;j<=n;j++)
		{
			if(!s[i][j])continue;
			if(j==u||j==v)continue;
			f1|=x[j][u];
			f2|=x[j][v];
		}
		if(!f1)
		{
			for(int j=1;j<=n;j++)
			{
				if(head[j]==0)
				{
					if(s[i][j])add(v,j),add(j,v);
					else add(u,j),add(j,u);
				}
			}
			break;
		}
	}
	for(int i=1;i<edgenum;i+=2)printf("%d %d\n",e[i].to,e[i+1].to);
	return 0;
}