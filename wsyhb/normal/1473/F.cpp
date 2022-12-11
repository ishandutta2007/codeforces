#include<bits/stdc++.h>
using namespace std;
int N,S,T;
const int max_N=3e3+5;
const int max_M=39e3+5;
const int inf=1e9;
int End[max_M<<1],Last[max_N],Next[max_M<<1],cap[max_M<<1],e=1;
inline void add_edge(int x,int y,int c)
{
//	fprintf(stderr,"x=%d y=%d c=%d\n",x,y,c);
	End[++e]=y;
	Next[e]=Last[x];
	Last[x]=e;
	cap[e]=c;
	End[++e]=x;
	Next[e]=Last[y];
	Last[y]=e;
	cap[e]=0;
}
int dis[max_N],q[max_N],_head,_tail;
int Last1[max_N],cnt[max_N];
void bfs()
{
	for(int i=1;i<=N;++i)
		dis[i]=N,cnt[i]=0;
	dis[T]=0;
	_head=1,_tail=0;
	q[++_tail]=T;
	while(_head<=_tail)
	{
		int x=q[_head++];
		for(int i=Last[x];i;i=Next[i])
		{
			int y=End[i];
			if(cap[i^1]>0&&dis[y]>dis[x]+1)
			{
				dis[y]=dis[x]+1;
				q[++_tail]=y;
			}
		}
	}
//	for(int i=1;i<=N;++i)
//		fprintf(stderr,"i=%d dis[i]=%d\n",i,dis[i]);
	for(int i=1;i<=N;++i)
	{
		Last1[i]=Last[i];
		++cnt[dis[i]];
	}
}
int dfs(int x,int flow)
{
	if(x==T)
		return flow;
//	fprintf(stderr,"dfs(%d,%d)\n",x,flow);
	int flow_now=0;
	for(int &i=Last1[x];i;i=Next[i])
	{
		int y=End[i];
//		fprintf(stderr,"y=%d\n",y);
		if(dis[x]==dis[y]+1&&cap[i]>0)
		{
//			fprintf(stderr,"x=%d y=%d\n",x,y);
			int f=dfs(y,min(cap[i],flow-flow_now));
			flow_now+=f;
			cap[i]-=f;
			cap[i^1]+=f;
//			fprintf(stderr,"f=%d\n",f);
			if(flow==flow_now||dis[S]==N)
				return flow_now;
		}
	}
	Last1[x]=Last[x];
	if(!(--cnt[dis[x]]))
	{
		dis[S]=N;
//		fprintf(stderr,"unconnected\n");
	}
	++cnt[++dis[x]];
	return flow_now;
}
const int max_n=3e3+5;
int a[max_n],b[max_n];
const int max_a=100+5;
int pos[max_a];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1;i<=n;++i)
		scanf("%d",b+i);
	N=n+2,S=n+1,T=n+2;
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		if(b[i]>0)
		{
			add_edge(S,i,b[i]);
			ans+=b[i];
		}
		else if(b[i]!=0)
			add_edge(i,T,-b[i]);
		for(int j=1;j<=a[i];++j)
		{
			if(a[i]%j==0&&pos[j]!=0)
				add_edge(i,pos[j],inf);
		}
		pos[a[i]]=i;
	}
	bfs();
	int flow=0;
	while(dis[S]<N)
		flow+=dfs(S,inf);
	printf("%d\n",ans-flow);
	return 0;
}