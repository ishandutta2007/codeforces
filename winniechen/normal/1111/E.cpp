#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 100005
#define ll long long
#define mod 1000000007
struct node{int to,next;}e[N<<1];
int head[N],cnt,fa[N],anc[N],dep[N],siz[N],son[N],idx[N],tims,n,Q;
void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;}
void dfs1(int x,int from)
{
	siz[x]=1,fa[x]=from,dep[x]=dep[from]+1;
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from)dfs1(to1,x),siz[x]+=siz[to1],siz[son[x]]<siz[to1]?son[x]=to1:0;
	}
}
void dfs2(int x,int top)
{
	anc[x]=top;idx[x]=++tims;if(son[x])dfs2(son[x],top);
	for(int i=head[x];i!=-1;i=e[i].next)if(e[i].to!=fa[x]&&e[i].to!=son[x])dfs2(e[i].to,e[i].to);
}
int get_lca(int x,int y)
{
	while(anc[x]!=anc[y])
	{
		if(dep[anc[x]]<dep[anc[y]])swap(x,y);
		x=fa[anc[x]];
	}return dep[x]<dep[y]?x:y;
}
bool cmp(const int &a,const int &b){return idx[a]<idx[b];}
int q[N],size,vis[N],sta[N],top,m,now;
int f[305];
void dfs(int x,int from)
{
	if(vis[x]){for(int i=m;i>=now;i--)(f[i+1]+=f[i])%=mod,f[i]=(ll)f[i]*(i-now)%mod;now++;}
	for(int i=head[x];i!=-1;i=e[i].next)if(e[i].to!=from)dfs(e[i].to,x);
	head[x]=-1;if(vis[x])now--;vis[x]=0;
	// printf("%d\n",x);
	// for(int i=0;i<=m;i++)printf("%d ",f[x][i]);puts("");
}
void build(int r)
{
	f[0]=1;for(int i=1;i<=m;i++)f[i]=0;
	bool used_r=0;top=0;cnt=0;
	for(int i=1;i<=size;i++)if(q[i]==r){used_r=1;break;}if(!used_r)q[++size]=r;sort(q+1,q+size+1,cmp);
	sta[++top]=1;
	for(int i=1;i<=size;i++)
	{
		int x=q[i],lca=get_lca(sta[top],x);if(!used_r&&r==q[i])vis[x]=0;else vis[x]=1;
		while(top>1&&dep[sta[top-1]]>=dep[lca])add(sta[top-1],sta[top]),add(sta[top],sta[top-1]),top--;
		if(sta[top]!=lca)add(lca,sta[top]),add(sta[top],lca),sta[top]=lca;if(x!=sta[top])sta[++top]=x;
	}while(top>1)add(sta[top-1],sta[top]),add(sta[top],sta[top-1]),top--;
	dfs(r,0);int ans=0;
	for(int i=1;i<=m;i++)ans=(ans+f[i])%mod;printf("%d\n",(ans+mod)%mod);
}
int main()
{
	scanf("%d%d",&n,&Q);memset(head,-1,sizeof(head));
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);dfs1(1,0);dfs2(1,1);memset(head,-1,sizeof(head));
	while(Q--)
	{
		int r;
		scanf("%d%d%d",&size,&m,&r);
		for(int i=1;i<=size;i++)scanf("%d",&q[i]);
		build(r);
	}
}
//