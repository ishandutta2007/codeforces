#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <queue>
#include <bitset>
using namespace std;
#define N 155
bool vis[N];bitset<N> a[N];
int dis[N],n,m;
struct node
{
	bitset<N> a[N];
	friend node operator*(const node &a,const node &b)
	{
		node c;memset(c.a,0,sizeof(c.a));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a.a[i][j])c.a[i]|=b.a[j];
			}
		}
		return c;
	}
}map,ret;
struct no
{
	int x,y,d;
	friend bool operator<(const no &a,const no &b)
	{
		return a.d<b.d;
	}
}E[N];
/*
void print(const node &a)
{
	puts("");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d ",a.a[i][j]);
		}
		puts("");
	}
	puts("");
}
*/
void q_pow(int x)
{
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)map.a[i][j]=a[i][j];
	while(x)
	{
		if(x&1)ret=ret*map;
		map=map*map,x=x>>1;
	}
}
bool bfs()
{
	queue <int >q;memset(dis,0,sizeof(dis));memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)if(ret.a[1][i])q.push(i),vis[i]=1,dis[i]=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=1;i<=n;i++)
		{
			if(a[x][i]&&!vis[i])vis[i]=1,dis[i]=dis[x]+1,q.push(i);
		}
	}
	return vis[n];
}
int main()
{
	// freopen("travel.in","r",stdin);
	// freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&E[i].x,&E[i].y,&E[i].d);
	sort(E+1,E+m+1);int last=0,j=0,ans=0x7fffffff;ret.a[1][1]=1;
	while(1)
	{
		for(int i=j+1;i<=m;i++)
		{
			if(E[i].d>last)break;
			a[E[i].x][E[i].y]=1;j++;
		}
		if(bfs()){ans=min(last+dis[n],ans);}
		if(j==m)break;
		q_pow(E[j+1].d-last);//print(ret);
		last=E[j+1].d;
	}
	if(ans==0x7fffffff)puts("Impossible");
	else printf("%d\n",ans);
	return 0;
}