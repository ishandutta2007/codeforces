#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 2005
#define S 0
#define T 2001
#define ll long long
struct node{int to,next;ll val;}e[N<<4];
int head[N],cnt,dep[N],n,m;ll ans=0;
void add(int x,int y,ll z){e[cnt]=(node){y,head[x],z};head[x]=cnt++;}
void insert(int x,int y,ll z){add(x,y,z);add(y,x,0);}
int bfs()
{
	memset(dep,-1,sizeof(dep));dep[S]=1;queue<int>q;q.push(S);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=head[x];i!=-1;i=e[i].next)
		{
			int to1=e[i].to;
			if(dep[to1]==-1&&e[i].val)dep[to1]=dep[x]+1,q.push(to1);
		}
	}return dep[T]==-1?0:1;
}
ll dfs(int x,ll maxf)
{
	if(x==T)return maxf;ll tflow=maxf,nowf;
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(e[i].val&&dep[x]+1==dep[to1])
		{
			nowf=dfs(to1,min(tflow,e[i].val));
			if(!nowf){dep[to1]=-1;continue;}
			e[i].val-=nowf,e[i^1].val+=nowf,tflow-=nowf;
			if(!tflow)break;
		}
	}dep[x]=-1;
	return maxf-tflow;
}
int main()
{
	scanf("%d%d",&n,&m);ll sum=0;memset(head,-1,sizeof(head));
	for(int i=1,x;i<=n;i++)scanf("%d",&x),insert(i,T,x);
	for(int i=1,x,y,z;i<=m;i++)
		scanf("%d%d%d",&x,&y,&z),
		insert(S,n+i,z),insert(n+i,x,1ll<<60),
		insert(n+i,y,1ll<<60),sum+=z;
	while(bfs())sum-=dfs(S,1ll<<60);
	printf("%lld\n",sum);
}