#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[4000005];
int t,n,m,edgenum,pa[1000005],size[1000005],dep[1000005],head[1000005];
char s[1005][1005];
queue<int>q;
int find(int x)
{
	return x==pa[x]?x:pa[x]=find(pa[x]);
}
void _add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void add(int u,int v)
{
	u=find(u),v=find(v);
	_add(u,v);
	_add(v,u);
}
void bfs()
{
	memset(dep,0x3f,sizeof(dep));
	while(!q.empty()) q.pop();
	for(int i=1;i<=n*m;i++)
	{
		if(find(i)==i&&size[i]>1)
		{
			dep[i]=0;
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(dep[to]>dep[node]+1)
			{
				dep[to]=dep[node]+1;
				q.push(to);
			}
		}
	}
}
void merge(int u,int v)
{
	u=find(u),v=find(v);
	if(u!=v)
	{
		pa[v]=u;
		size[u]+=size[v];
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n*m;i++)pa[i]=i,size[i]=1;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<m;j++)
	    if(s[i][j]==s[i][j+1])
	      merge((i-1)*m+j,(i-1)*m+j+1);
	for(int i=1;i<n;i++)
	  for(int j=1;j<=m;j++)
	    if(s[i][j]==s[i+1][j])
	      merge((i-1)*m+j,i*m+j);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<m;j++)
	    if(s[i][j]!=s[i][j+1])
	      add((i-1)*m+j,(i-1)*m+j+1);
	for(int i=1;i<n;i++)
	  for(int j=1;j<=m;j++)
	    if(s[i][j]!=s[i+1][j])
	      add((i-1)*m+j,i*m+j);
	bfs();
	while(t--)
	{
		int x,y;
		ll t;
		scanf("%d%d%lld",&x,&y,&t);
		int p=find((x-1)*m+y);
		if(dep[p]>=1000000000||dep[p]>=t)
		{
			printf("%c\n",s[x][y]);
			continue;
		}
		t-=dep[p];
		printf("%lld\n",(t&1)^(s[x][y]=='1'));
	}
	return 0;
}