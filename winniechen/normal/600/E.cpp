#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
#define N 100005
struct node{int to,next;}e[N<<1];
int head[N],val[N],col[N],maxx,siz[N],son[N],n,cnt;long long ans[N],sum;
void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;}
void dfs1(int x,int from)
{
	siz[x]=1;
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from)dfs1(to1,x),siz[x]+=siz[to1],son[x]=(siz[to1]>siz[son[x]]?to1:son[x]);
	}
}
void add(int x,int from,int c)
{
	col[val[x]]+=c;
	if(col[val[x]]>=maxx&&c>0)
	{
		if(col[val[x]]>maxx)maxx=col[val[x]],sum=0;
		sum+=val[x];
	}
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from)add(to1,x,c);
	} 
}
void dfs2(int x,int from,int op)
{
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from&&to1!=son[x])dfs2(to1,x,0);
	}if(son[x])dfs2(son[x],x,1);
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from&&to1!=son[x])add(to1,x,1);
	}
	col[val[x]]++;
	if(col[val[x]]>=maxx)
	{
		if(col[val[x]]>maxx)maxx=col[val[x]],sum=0;
		sum+=val[x];
	}
	ans[x]=sum;
	if(!op)add(x,from,-1),sum=0,maxx=0;
}
int main()
{
	scanf("%d",&n);memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)scanf("%d",&val[i]);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);
	dfs1(1,0);dfs2(1,0,1);
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]);return 0;
}