// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
const int Maxn=5005;
int s,t,n,m,head[Maxn],cur[Maxn],cnt,ct,dis[Maxn],bel[Maxn],e[Maxn];
long long ans;
struct edg
{
	int nxt,to;
	long long w;
}edge[2*Maxn];
void add(int x,int y,int w)
{
	edge[++cnt]=(edg){head[x],y,w};
	head[x]=cnt;
	edge[++cnt]=(edg){head[y],x,0};
	head[y]=cnt;
}
queue <int> Qu; 
bool bfs(void)
{
	Qu.push(s);
	memset(dis,0,sizeof(int[ct+1])); 
	while(!Qu.empty())
	{
		int u=Qu.front();
		Qu.pop();
		for(int i=head[u];i;i=edge[i].nxt)
		{
			int to=edge[i].to;
			if(!dis[to]&&to!=s&&edge[i].w) dis[to]=dis[u]+1,Qu.push(to);
		}
	}
	return (bool)dis[t];
}
long long dfs(int u,long long mini)
{
	if(!mini||u==t) return mini;
	long long w,used=0;
	for(int &i=cur[u];i;i=edge[i].nxt)
	{
		int to=edge[i].to;
		if(dis[to]==dis[u]+1&&edge[i].w)
		{
			w=dfs(to,min(mini-used,edge[i].w));
			used+=w,edge[i].w-=w,edge[((i-1)^1)+1].w+=w;
		}
	}
	return used;
}
void dinic(void)
{
	while(bfs())
	{
		memcpy(cur,head,sizeof(int[ct+1]));
		ans-=dfs(s,0x3f3f3f3f3f3f3f3f);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	s=++ct,t=++ct;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		bel[i]=++ct;
		add(s,bel[i],x);
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		e[i]=++ct;
		add(bel[x],e[i],0x3f3f3f3f);
		add(bel[y],e[i],0x3f3f3f3f);
		add(e[i],t,w);
		ans+=w;
	}
	dinic();
	printf("%lld",ans);
	return 0;
}