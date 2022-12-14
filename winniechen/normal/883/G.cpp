#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 600005
struct node{int to,next;}e[N];
struct edge{int x,y,op;}a[N];
int vis[N],head[N],cnt,n,m,S,ans[N],used[N];
void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;}
int bfs(int S)
{
	queue<int >q;q.push(S);vis[S]=1;int ret=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=head[x];i!=-1;i=e[i].next)
		{
			if(used[i])continue;
			int to1=e[i].to;used[i]=used[i^1]=1;
			if(i&1)ans[(i>>1)+1]=1;
			if(!vis[to1])q.push(to1),ret++,vis[to1]=1;
		}
	}return ret;
}
int Bfs()
{
	queue<int >q;q.push(S);vis[S]=1;int ret=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=head[x];i!=-1;i=e[i].next)
		{
			int to1=e[i].to;
			if(!vis[to1])q.push(to1),ret++,vis[to1]=1;
		}
	}return ret;
}
int main()
{
	scanf("%d%d%d",&n,&m,&S);memset(head,-1,sizeof(head));
	for(int i=1;i<=m;i++)scanf("%d%d%d",&a[i].op,&a[i].x,&a[i].y);
	for(int i=1;i<=m;i++)
	{
		add(a[i].x,a[i].y);
		if(a[i].op==1)used[cnt]=1;
		add(a[i].y,a[i].x);
	}
	printf("%d\n",bfs(S));
	for(int i=1;i<=m;i++)
	{
		if(a[i].op==1)continue;
		printf("%c",ans[i]?'-':'+');
	}puts("");
	memset(head,-1,sizeof(head));cnt=0;memset(vis,0,sizeof(vis));
	for(int i=1;i<=m;i++)if(a[i].op==1)add(a[i].x,a[i].y);
	printf("%d\n",Bfs());
	for(int i=1;i<=m;i++)
	{
		if(a[i].op==1)continue;
		if(vis[a[i].x]&&vis[a[i].y])printf("+");
		else if(vis[a[i].x])printf("-");
		else if(vis[a[i].y])printf("+");
		else printf("+");
	}puts("");
}