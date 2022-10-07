#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
struct Edge
{
	int from;
	int to;
	int nxt;
	int len;
}e[24005],E[24005];
int n,k,edgenum,Edgenum,a[200005],p[125][6],times[125][125],now[6],num,head[125],pa[125],dis[125];
bool flag[125];
queue<int>q;
void add(int u,int v,int l)
{
	e[++edgenum].to=v;
	e[edgenum].from=u;
	e[edgenum].len=l;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs_pre(int step)
{
	if(step>n)
	{
		num++;
		for(int i=1;i<=n;i++)p[num][i]=now[i];
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(flag[i])continue;
		now[step]=i;
		flag[i]=1;
		dfs_pre(step+1);
		flag[i]=0;
	}
}
bool cmp(Edge a,Edge b)
{
	return a.len>b.len;
}
int find(int x)
{
	return x==pa[x]?x:pa[x]=find(pa[x]);
}
int main()
{
	scanf("%d%d",&k,&n);
	dfs_pre(1);
	for(int i=1;i<=num;i++)
	{
		for(int j=1;j<=num;j++)
		{
			for(int x=1;x<=n;x++)
			  now[x]=p[j][p[i][x]];
			for(int k=1;k<=num;k++)
			{
				bool flag=1;
				for(int x=1;x<=n;x++)
				{
					if(now[x]!=p[k][x])
					{
						flag=0;
						break;
					}
				}
				if(flag)
				{
					times[i][j]=k;
					break;
				}
			}
		}
	}
	swap(n,k);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)scanf("%d",&now[j]);
		for(int j=1;j<=num;j++)
		{
			bool flag=1;
			for(int l=1;l<=k;l++)
			{
				if(now[l]!=p[j][l])
				{
					flag=0;
					break;
				}
			}
			if(flag)
			{
				a[i]=j;
				break;
			}
		}
		for(int i=1;i<=edgenum;i++)e[i]=E[i];
		edgenum=Edgenum;
		Edgenum=0;
		for(int x=1;x<=num;x++)
		{
			e[++edgenum].from=x;
			e[edgenum].to=times[x][a[i]];
			e[edgenum].len=i;
		}
		sort(e+1,e+edgenum+1,cmp);
		for(int i=1;i<=num;i++)pa[i]=i,head[i]=0,dis[i]=0;
		for(int i=1;i<=edgenum;i++)
		{
			int u=e[i].from;
			int v=e[i].to;
			if(find(u)!=find(v))
			{
				pa[find(u)]=find(v);
				E[++Edgenum]=e[i];
			}
		}
		edgenum=0;
		for(int i=1;i<=Edgenum;i++)
		{
			add(E[i].from,E[i].to,E[i].len);
			add(E[i].to,E[i].from,E[i].len);
		}
		q.push(1);
		dis[1]=i;
		while(!q.empty())
		{
			int node=q.front();
			q.pop();
			for(int hd=head[node];hd;hd=e[hd].nxt)
			{
				int to=e[hd].to;
				if(dis[to]!=0)continue;
				dis[to]=max(dis[to],min(dis[node],e[hd].len));
				q.push(to);
			}
		}
		for(int i=1;i<=num;i++)ans+=dis[i];
	}
	printf("%lld\n",ans);
	return 0;
}