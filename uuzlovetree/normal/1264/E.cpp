#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 5005
using namespace std;
int T;
int n,m;
int head[maxn],p,s,t;
struct edge
{
    int to,next,f,c;
}e[maxn*10];
void addedge(int u,int v,int f,int c)
{
    e[p].to=v;e[p].f=f;e[p].c=c;e[p].next=head[u];head[u]=p++;
    e[p].to=u;e[p].f=0;e[p].c=-c;e[p].next=head[v];head[v]=p++;
}
int dis[maxn],inq[maxn],pre[maxn];
bool vis[maxn];
bool spfa(int s,int t)
{
    memset(inq,0,sizeof(inq));
    queue<int> q;
    for(int i=s;i<=t;i++)dis[i]=inf;dis[s]=0;
    q.push(s);inq[s]=1;
    while(!q.empty())
    {
        int u=q.front();q.pop();inq[u]=0;
        for(int i=head[u];i!=-1;i=e[i].next)
        {
            int v=e[i].to,f=e[i].f,c=e[i].c;
            if(f&&dis[v]>dis[u]+c)
            {
                dis[v]=dis[u]+c;
                if(!inq[v])inq[v]=1,q.push(v);
            }
        }
    }
    return dis[t]!=inf;
}
int dfs(int u,int maxf,int t)
{
    if(u==t)return maxf;int tmp=0;
    vis[u]=1;
    for(int i=head[u];i!=-1&&tmp<maxf;i=e[i].next)if(!vis[e[i].to])
    {
        int v=e[i].to,f=e[i].f,c=e[i].c;
        if(f&&dis[v]==dis[u]+c)
        {
            int minn=min(maxf-tmp,f);
            f=dfs(v,minn,t);
			tmp+=f;e[i].f-=f;e[i^1].f+=f;
        }
    }
    return tmp;
}
int mcmf(int s,int t)
{
    int ans=0;
    while(spfa(s,t))
    {
        memset(vis,0,sizeof(vis));
        ans+=dfs(s,inf,t)*dis[t];
    }
    return ans;
}
int win[55][55],a[55][55];
int main()
{
    scanf("%d%d",&n,&m);
    memset(head,-1,sizeof(head));
    p=0;s=0;t=5001;
    for(int i=1;i<=m;++i)
    {
    	int u,v;
    	scanf("%d%d",&u,&v);
    	a[u][v]=1;
	}
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)if(!a[i][j]&&!a[j][i])a[i][j]=a[j][i]=2;
	int cnt=n;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<i;++j)
		{
			addedge(s,++cnt,1,0);
			if(a[i][j]==0||a[i][j]==2)addedge(cnt,i,1,0),win[j][i]=p-1;
			if(a[i][j]==1||a[i][j]==2)addedge(cnt,j,1,0),win[i][j]=p-1;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<n;j++)addedge(i,t,1,j);
	int ans=n*(n-1)*(n-2)/6;
	ans-=mcmf(s,t);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(i==j)printf("0");
			else if(a[i][j]==0||a[i][j]==1)printf("%d",a[i][j]);
			else printf("%d",e[win[i][j]].f?1:0);//,cerr<<endl<<i<<" "<<j<<" "<<e[win[i][j]].f<<endl;
		}
		puts("");
	}
}