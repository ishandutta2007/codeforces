#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 75
priority_queue<pair<int ,pair<int ,int > > >q;
struct node{int to,next,val;}e[505];
int head[N],edge_cnt,fa[N],siz[N],mrk[N],cnt,dis[N][1<<17],vis[N][1<<17],n,m,a,b;
void add(int x,int y,int z){e[edge_cnt]=(node){y,head[x],z};head[x]=edge_cnt++;}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline void merge(int x,int y){x=find(x),y=find(y);if(x==y)return ;siz[x]+=siz[y],fa[y]=x;}
inline void Push(int x,int S,int v)
{
	if(dis[x][S]>v)
		dis[x][S]=v,q.push(make_pair(-dis[x][S],make_pair(x,S)));
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&a,&b);memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1,mrk[i]=-1;
	for(int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(z==a)merge(x,y);add(x,y,z),add(y,x,z);
	}
	for(int i=1;i<=n;i++)
		if(mrk[i]==-1&&siz[find(i)]>3)
		{
			for(int j=i;j<=n;j++)if(find(i)==find(j))mrk[j]=cnt;
			cnt++;
		}
	memset(dis,0x3f,sizeof(dis));Push(1,(mrk[1]==-1?0:(1<<mrk[1])),0);
	while(!q.empty())
	{
		int x=q.top().second.first,S=q.top().second.second;q.pop();
		if(vis[x][S])continue;vis[x][S]=1;
		for(int i=head[x];i!=-1;i=e[i].next)
		{
			int to1=e[i].to;
			if(e[i].val==a)Push(to1,S,dis[x][S]+a);
			else if(find(to1)!=find(x)&&(S&(mrk[to1]==-1?0:(1<<mrk[to1])))==0)
				Push(to1,S|(mrk[to1]==-1?0:(1<<mrk[to1])),dis[x][S]+b);
		}
	}
	for(int i=1;i<=n;i++)
	{
		int ret=1<<30;
		for(int S=0;S<(1<<cnt);S++)ret=min(ret,dis[i][S]);
		printf("%d\n",ret);
	}
}