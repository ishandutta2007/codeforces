#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <bitset>
using namespace std;
#define N 500005
struct node{int to,next;}e[N<<1];
struct edge{int x,y,v;}a[N];
int head[N],dep[N],cnt,fa[N],num,n,m,k;long long ans;
struct A
{
	int f[N],siz[N];
	void init(){for(int i=0;i<N;i++)f[i]=i,siz[i]=1;}
	int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
	void uni(int x,int y,int op)
	{
		x=find(x),y=find(y);
		if(siz[x]>siz[y])swap(x,y);
		f[x]=y;siz[y]+=siz[x];
		if(op&&dep[y]>dep[x])fa[y]=fa[x],dep[y]=dep[x];
	}
}A,B;
void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;}
void dfs(int x,int from)
{
	fa[x]=from,dep[x]=dep[from]+1;
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from)dfs(to1,x);
	}
}
void get_lca(int x,int y,int v)
{
	int fx=A.find(x),fy=A.find(y);
	while(fx!=fy)
	{
		// printf("%d %d %d\n",x,y,v);
		if(dep[fx]<dep[fy])swap(fx,fy),swap(x,y);
		A.uni(fx,fa[fx],1),ans+=v,num++;
		fx=A.find(x),fy=A.find(y);
	}
}
int main()
{
	scanf("%d%d%d",&n,&k,&m);memset(head,-1,sizeof(head));A.init(),B.init();
	for(int i=1,x,y;i<=k;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x),B.uni(x,y,0);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
	for(int i=1;i<=m;i++)
		if(B.find(a[i].x)!=B.find(a[i].y))
			add(a[i].x,a[i].y),add(a[i].y,a[i].x),B.uni(a[i].x,a[i].y,0),num--,ans-=a[i].v;
	for(int i=1;i<=n;i++)if(!fa[i])dfs(i,0);
	for(int i=1;i<=m;i++)get_lca(a[i].x,a[i].y,a[i].v);
	if(num<k)puts("-1");
	else printf("%lld\n",ans);
}