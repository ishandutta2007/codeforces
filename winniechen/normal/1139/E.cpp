#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
#include <map>
using namespace std;
#define N 10005
#define S 0
#define T 10001
int p[N],n,m,Q,bel[N],t[N],tot,used[N];
struct node{int to,next,val;}e[N*20];
int head[N],cnt,dep[N],q[N],ans[N];
void add(int x,int y,int z){e[cnt]=(node){y,head[x],z};head[x]=cnt++;}
void insert(int x,int y,int z){add(x,y,z),add(y,x,0);}
int bfs()
{
	int l=0,r=0;memset(dep,-1,sizeof(dep));q[r++]=S;dep[S]=1;
	while(l<r)
	{
		int x=q[l++];
		for(int i=head[x];i!=-1;i=e[i].next)
		{
			int to1=e[i].to;
			if(dep[to1]==-1&&e[i].val)q[r++]=to1,dep[to1]=dep[x]+1;
		}
	}return dep[T]==-1?0:1;
}
int dfs(int x,int maxf)
{
	if(x==T)return maxf;int tflow=maxf,nowf;
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(dep[to1]==dep[x]+1&&e[i].val)
		{
			nowf=dfs(to1,min(tflow,e[i].val));
			e[i].val-=nowf,e[i^1].val+=nowf,tflow-=nowf;
			if(!tflow)break;
		}
	}if(tflow)dep[x]=-1;return maxf-tflow;
}
int main()
{
	scanf("%d%d",&n,&m);memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)scanf("%d",&bel[i]);scanf("%d",&Q);
	for(int i=1;i<=Q;i++)scanf("%d",&t[i]),used[t[i]]=1;int tot=m;
	for(int i=1;i<=m;i++)insert(S,i,1);
	for(int i=1;i<=n;i++)if(!used[i])insert(bel[i],p[i]+m+1,1);
	int now=-1,lst=0;
	for(int cas=Q;cas;cas--)
	{
		for(;lst<=m&&lst==now+1;lst++)
		{
			insert(lst+m+1,T,1);
			while(bfs())now+=dfs(S,1<<30);
		}
		insert(bel[t[cas]],p[t[cas]]+m+1,1);ans[cas]=now+1;
		while(bfs())now+=dfs(S,1<<30);
	}
	for(int i=1;i<=Q;i++)printf("%d\n",ans[i]);
}