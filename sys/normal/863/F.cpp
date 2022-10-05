// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
const int Maxn=10005;
int tot_flow,n,q,s,t,head[Maxn],cnt,dis[Maxn],from[Maxn],las[Maxn],ct,giv[Maxn],num[Maxn];
bool choose[55][55];
struct edg
{
	int nxt,to,w,c;
}edge[2*Maxn];
void add(int x,int y,int w,int c)
{
	edge[++cnt]=(edg){head[x],y,w,c};
	head[x]=cnt;
	edge[++cnt]=(edg){head[y],x,0,-c};
	head[y]=cnt;
}
queue <int> Qu;
bool vis[Maxn]; 
bool SPFA(void)
{
	Qu.push(s);
	vis[s]=true;
	memset(dis,0x3f,sizeof(int[ct+1]));
	dis[s]=0;
	while(!Qu.empty())
	{
		int u=Qu.front();
		Qu.pop();
		vis[u]=false;
		for(int i=head[u];i;i=edge[i].nxt)
		{
			int to=edge[i].to;
			if(edge[i].w&&dis[u]+edge[i].c<dis[to])
			{
				dis[to]=dis[u]+edge[i].c;
				from[to]=u;
				las[to]=i;
				if(!vis[to]) Qu.push(to),vis[to]=true;
			}
		}
	}
	return dis[t]!=0x3f3f3f3f;
}
int MCMF(void)
{
	int ans=0;
	while(SPFA())
	{
		int u=t,tot=0,flow=0x3f3f3f3f;
		while(u!=1)
		{
			flow=min(flow,edge[las[u]].w);
			tot+=edge[las[u]].c;
			u=from[u];
		}
		u=t;
		while(u!=1)
		{
			edge[las[u]].w-=flow,edge[((las[u]-1)^1)+1].w+=flow;
			u=from[u];
		}
		ans+=tot*flow;
	}
	for(int u=1;u<=n;u++)
		for(int i=head[num[u]];i;i=edge[i].nxt)
		{
			int to=edge[i].to;
			if(to==t&&edge[i].w) ans=-1;
		}
	return ans;
}
int main()
{
//	freopen("863F.in","r",stdin);
	scanf("%d%d",&n,&q);
	s=++ct,t=++ct;
	for(int i=1;i<=n;i++)
	{
		giv[i]=++ct;
		for(int j=1;j<=n;j++)
			add(s,giv[i],1,2*j-1);
	}
	for(int i=1;i<=n;i++)
	{ 
		num[i]=++ct;
		add(num[i],t,1,0);
	}
	memset(choose,true,sizeof(choose));
	for(int i=1;i<=q;i++)
	{
		int opt,l,r,v;
		scanf("%d%d%d%d",&opt,&l,&r,&v);
		if(opt==1)
			for(int i=1;i<v;i++)
				for(int j=l;j<=r;j++)
					choose[j][i]=false;
		else 
			for(int i=v+1;i<=n;i++)
				for(int j=l;j<=r;j++)
					choose[j][i]=false;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(choose[i][j]) add(giv[j],num[i],1,0);
	printf("%d",MCMF());
	return 0;
}