#include<bits/stdc++.h>
#define maxn 400005
using namespace std;
int n;
int head[maxn],p;
struct edge
{
	int to,next,w;
}e[maxn<<1];
void addedge(int u,int v,int w)
{
	e[++p].to=v;e[p].w=w;e[p].next=head[u];head[u]=p;
}
int res1=0;
void dfs1(int u,int fa)
{
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to,w=e[i].w;
		if(v==fa)continue;
		res1+=w;
		dfs1(v,u);
	}
}
int has0=0,has1=0;
int Ans[maxn];
void dfs2(int u,int fa)
{
	Ans[u]=res1-has1+has0;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to,w=e[i].w;
		if(v==fa)continue;
		if(w)has1++;else has0++;
		dfs2(v,u);
		if(w)has1--;else has0--;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v,0);
		addedge(v,u,1);
	}
	dfs1(1,0);
	dfs2(1,0);
	int ans=n;
	for(int i=1;i<=n;++i)ans=min(ans,Ans[i]);
	printf("%d\n",ans);
	for(int i=1;i<=n;++i)if(Ans[i]==ans)printf("%d ",i);
	puts("");
	return 0; 
}