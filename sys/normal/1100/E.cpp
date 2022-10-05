#include <bits/stdc++.h>
using namespace std;
const int Maxn=100005;
int n,m,head[Maxn],cnt,maxi,ct[Maxn],dfn[Maxn],ans[Maxn],tot,vis[Maxn];
struct edg
{
	int nxt,to,w;
}edge[Maxn];
void add(int x,int y,int w)
{
	edge[++cnt]=(edg){head[x],y,w};
	head[x]=cnt;
}
int lim; 
bool dfs(int u,int id)
{
	vis[u]=-1;
	for(int i=head[u];i;i=edge[i].nxt)
	{
		int to=edge[i].to;
		if(edge[i].w<=lim) continue;
		if(vis[to]!=-1&&vis[to]) continue;
		if(vis[to]==-1||dfs(to,id)) return true;
	}
	vis[u]=id;
	return false;
}
bool in[Maxn];
void work(int x)
{
	queue <int> Qu;
	int c=0;
	for(int i=1;i<=m;i++)
		if(edge[i].w>lim)
			ct[edge[i].to]++;
	for(int i=1;i<=n;i++)
		if(!ct[i]) Qu.push(i),in[i]=true;
	while(!Qu.empty())
	{
		int u=Qu.front();
		Qu.pop();
		dfn[u]=++c;
		for(int i=head[u];i;i=edge[i].nxt)
		{
			int to=edge[i].to;
			if(edge[i].w>lim)
			{
				ct[to]--;
				if(!ct[to]&&!dfn[to]&&!in[to]) in[to]=true,Qu.push(to);
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		add(x,y,w);
		maxi=max(maxi,w);
	}
	int lt=0,rt=maxi;
	while(lt+1<=rt)
	{
		int mid=(lt+rt)/2;
		lim=mid;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
			if(!vis[i]&&dfs(i,i))
			{
				lt=mid+1;
				goto A;
			}
		rt=mid;
		A:;
	}
	lim=lt;
	work(lt);
	for(int u=1;u<=n;u++)
		for(int i=head[u];i;i=edge[i].nxt)
		{
			int to=edge[i].to;
			if(edge[i].w<=lt)
				if(dfn[to]<dfn[u]) ans[++tot]=i;
		}
	printf("%d %d\n",lt,tot);
	for(int i=1;i<=tot;i++) printf("%d ",ans[i]); 
	return 0;
}