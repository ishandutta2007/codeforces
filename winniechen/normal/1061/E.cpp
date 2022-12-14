#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
#include <set>
using namespace std;
#define N 505
#define S 0
#define T 1001
#define ll long long
ll ans;int n,rot1,rot2,a[N],flo;
struct Flow
{
	struct node{int from,to,next;int val;int flow;}e[N*N*10];
	int head[N<<1],cnt,vis[N<<1],from[N<<1];queue<int>q;ll dis[N<<1];
	void init(){memset(head,-1,sizeof(head));}
	void add(int x,int y,int z,int f){e[cnt]=(node){x,y,head[x],z,f};head[x]=cnt++;}
	void insert(int x,int y,int z,int f){add(x,y,z,f);add(y,x,-z,0);}
	int spfa()
	{
		memset(dis,0xc0,sizeof(dis));dis[S]=0;q.push(S);memset(from,-1,sizeof(from));
		while(!q.empty())
		{
			int x=q.front();q.pop();vis[x]=0;
			for(int i=head[x];i!=-1;i=e[i].next)
			{
				int to1=e[i].to;
				if(dis[to1]<dis[x]+e[i].val&&e[i].flow)
				{
					dis[to1]=dis[x]+e[i].val;from[to1]=i;
					if(!vis[to1])q.push(to1),vis[to1]=1;
				}
			}
		}return from[T]==-1?0:1;
	}
	void mcfx()
	{
		int i=from[T],x=1<<30;
		while(i!=-1)x=min(x,e[i].flow),i=from[e[i].from];i=from[T];flo+=x;
		while(i!=-1)ans+=e[i].val*x,e[i].flow-=x,e[i^1].flow+=x,i=from[e[i].from];
	}
	void work(){while(spfa())mcfx();}
	void get_ans()
	{
		printf("%lld\n",ans);
		// ans=0;
		// for(int i=head[S];i!=-1;i=e[i].next)
			// if(e[i].val!=(1<<30)&&!e[i].flow)ans+=e[i].val,printf("%d\n",e[i].to);;
		// printf("%lld\n",ans);
	}
}A;
struct Tree
{
	struct node{int to,next;}e[N<<1];
	int head[N],cnt,fa[N],par[N],q[N];
	void init(){memset(head,-1,sizeof(head));}
	void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;}
	void dfs(int x,int from,int lst)
	{
		if(from&&q[x])q[lst]-=q[x],par[x]=lst=x;
		else par[x]=lst;
		for(int i=head[x];i!=-1;i=e[i].next)
		{
			int to1=e[i].to;
			if(to1!=from)dfs(to1,x,lst);
		}
	}
	bool check(){for(int i=1;i<=n;i++)if(q[i]<0)return 0;return 1;}
}t[2];
int main()
{
	A.init();t[0].init();t[1].init();
	scanf("%d%d%d",&n,&rot1,&rot2);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),t[0].add(x,y),t[0].add(y,x);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),t[1].add(x,y),t[1].add(y,x);
	int Q,sum=0;
	scanf("%d",&Q);
	for(int i=1,x,k;i<=Q;i++)scanf("%d%d",&x,&k),t[0].q[x]=k;
	scanf("%d",&Q);
	for(int i=1,x,k;i<=Q;i++)scanf("%d%d",&x,&k),t[1].q[x]=k;
	if(t[0].q[rot1]!=t[1].q[rot2])return puts("-1"),0;sum=t[0].q[rot1];
	t[0].dfs(rot1,0,rot1);t[1].dfs(rot2,0,rot2);
	if(!t[0].check()||!t[1].check())return puts("-1"),0;
	for(int i=1;i<=n;i++)
	{
		// printf("i=%d %d %d %d %d\n",i,t[0].par[i],t[1].par[i],t[0].q[i],t[1].q[i]);
		A.insert(t[0].par[i],t[1].par[i]+n,a[i],1);
		A.insert(S,i,0,t[0].q[i]);
		A.insert(i+n,T,0,t[1].q[i]);
	}
	A.work();
	if(flo!=sum)return puts("-1"),0;
	A.get_ans();
}