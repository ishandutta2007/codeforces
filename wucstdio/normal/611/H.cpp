#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int INF=2147483647;
struct Edge
{
	int to;
	int nxt;
	int flow;
}e[1005];
int n,m,tot,edgenum,s,t,r[7],now[7],a[7][7],id[7][7],head[35],dep[35],from[7],to[7],top,pa[7];
char ss[15],tt[15];
queue<int>q;
int find(int x)
{
	return x==pa[x]?x:find(pa[x]);
}
void add(int u,int v,int f)
{
	e[++edgenum].flow=f;
	e[edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int _dfs(int node,int nowf)
{
	if(node==t)return nowf;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		if(e[hd].flow==0)continue;
		int to=e[hd].to;
		if(dep[to]==dep[node]+1)
		{
			int d=_dfs(to,min(nowf,e[hd].flow));
			if(d)
			{
				e[hd].flow-=d;
				e[hd^1].flow+=d;
				return d;
			}
		}
	}
	return 0;
}
bool bfs()
{
	while(!q.empty())q.pop();
	memset(dep,0,sizeof(dep));
	dep[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			if(e[hd].flow==0)continue;
			int to=e[hd].to;
			if(!dep[to])
			{
				dep[to]=dep[node]+1;
				q.push(to);
			}
		}
		if(dep[t])return 1;
	}
	return dep[t];
}
int Dinic()
{
	int ans=0,d;
	while(bfs())
	{
		while((d=_dfs(s,INF)))
		  ans+=d;
	}
	return ans;
}
void dfs(int u,int v)
{
	if(v>m)
	{
		memset(head,0,sizeof(head));
		edgenum=1;
		s=m+tot+1,t=m+tot+2;
		int sum=0;
		for(int i=1;i<=m;i++)
		{
			if(i!=m)add(s,i,r[i+1]-now[i]-1);
			else add(s,i,n-now[i]);
			add(i,s,0);
		}
		for(int i=1;i<=m;i++)
		for(int j=i+1;j<=m;j++)
		{
			sum+=a[i][j];
			add(id[i][j]+m,t,a[i][j]);
			add(t,id[i][j]+m,0);
			add(i,id[i][j]+m,INF);
			add(id[i][j]+m,i,0);
			add(j,id[i][j]+m,INF);
			add(id[i][j]+m,j,0);
		}
		if(Dinic()==sum)
		{
			for(int i=1;i<=m;i++)now[i]=r[i];
			for(int i=1;i<=m;i++)
			{
				while(a[i][i])
				{
					printf("%d %d\n",r[i],++now[i]);
					a[i][i]--;
				}
			}
			for(int i=1;i<=top;i++)printf("%d %d\n",r[from[i]],r[to[i]]);
			for(int i=1;i<=m;i++)
			for(int j=i+1;j<=m;j++)
			{
				for(int hd=head[id[i][j]+m];hd;hd=e[hd].nxt)
				{
					int to=e[hd].to;
					if(to==i&&e[hd].flow)
					{
						for(int k=1;k<=e[hd].flow;k++)
						  printf("%d %d\n",++now[i],r[j]);
					}
					if(to==j&&e[hd].flow)
					{
						for(int k=1;k<=e[hd].flow;k++)
						  printf("%d %d\n",++now[j],r[i]);
					}
				}
			}
			exit(0);
		}
		return;
	}
	if(v==m)dfs(u+1,u+2);
	else dfs(u,v+1);
	if(find(u)!=find(v)&&a[u][v])
	{
		int x=find(u),y=find(v);
		pa[x]=y;
		from[++top]=u;
		to[top]=v;
		a[u][v]--,a[v][u]--;
		if(v==m)dfs(u+1,u+2);
		else dfs(u,v+1);
		a[u][v]++,a[v][u]++;
		pa[x]=x;
		top--;
	}
}
int main()
{
	scanf("%d",&n);
	r[1]=now[1]=1;
	for(int i=2;i<=6;i++)r[i]=now[i]=r[i-1]*10;
	m=6;
	while(r[m]>n)m--;
	for(int i=1;i<n;i++)
	{
		scanf("%s%s",ss,tt);
		int u=(int)strlen(ss),v=(int)strlen(tt);
		if(u==v)now[u]++;
		a[u][v]++;
		if(u!=v)a[v][u]++;
	}
	for(int i=1;i<m;i++)
	{
		if(now[i]>=r[i+1])
		{
			printf("-1\n");
			return 0;
		}
	}
	if(now[m]>n)
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=m;i++)
	  for(int j=i+1;j<=m;j++)
	    id[i][j]=++tot;
	for(int i=1;i<=m;i++)pa[i]=i;
	dfs(1,2);
	printf("-1\n");
	return 0;
}