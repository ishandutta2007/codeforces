#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 300005
#define ll long long
const ll inf = 1ll<<60;
int n,dep[N],Q,fa[N][19];
ll w[N];
struct Mat
{
	ll a[2][2];
	Mat(){memset(a,0x3f,sizeof(a));}
	Mat operator * (const Mat &b) const 
	{
		Mat c = Mat();
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++)
					c.a[i][j]=min(c.a[i][j],a[i][k]+b.a[k][j]);
		return c;
	}
	void print(){for(int i=0;i<2;i++,puts(""))for(int j=0;j<2;j++)printf("%lld ",a[i][j]);}
}f[N][19];
struct node{int to,next;ll w1,w2;}e[N<<1];
int head[N],cnt;
void add(int x,int y,ll z,ll w){e[cnt]=(node){y,head[x],z,w};head[x]=cnt++;}
void dfs1(int x,int from)
{
	fa[x][0]=from,dep[x]=dep[from]+1;
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from)dfs1(to1,x),w[x]=min(w[x],e[i].w1+e[i].w2+w[to1]);
	}
}
void dfs2(int x,int from)
{
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from)w[to1]=min(w[to1],w[x]+e[i].w1+e[i].w2),dfs2(to1,x);
	}
}
void dfs(int x,int from)
{
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from)
		{
			dfs(to1,x);
			f[to1][0].a[0][0]=min(e[i].w1,w[to1]+e[i].w2+w[x]);
			f[to1][0].a[1][1]=min(e[i].w2,w[to1]+e[i].w1+w[x]);
			f[to1][0].a[0][1]=min(e[i].w2+w[to1],e[i].w1+w[x]);
			f[to1][0].a[1][0]=min(e[i].w2+w[x],e[i].w1+w[to1]);
		}
	}
}
int get_lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);int deep=dep[x]-dep[y];
	for(int i=0;i<19;i++)if(deep>>i&1)x=fa[x][i];if(x==y)return x;
	for(int i=18;~i;i--)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];return fa[x][0];
}
void get_up(int x,int K,Mat &ret){for(int i=18;~i;i--)if(K>>i&1)ret=ret*f[x][i],x=fa[x][i];}
Mat ret1,ret2;
ll get_ans(int x,int y)
{
	int a=(x+1)>>1,b=(y+1)>>1,lca=get_lca(a,b);
	if(dep[a]<dep[b])swap(a,b),swap(x,y);
	ret1=Mat();ret1.a[0][x&1]=w[a],ret1.a[0][!(x&1)]=0;
	ret2=Mat();ret2.a[0][y&1]=w[b],ret2.a[0][!(y&1)]=0;
	get_up(a,dep[a]-dep[lca],ret1);get_up(b,dep[b]-dep[lca],ret2);
	return min(ret1.a[0][0]+ret2.a[0][0],ret1.a[0][1]+ret2.a[0][1]);
}
int main()
{
	scanf("%d",&n);memset(head,-1,sizeof(head));ll w1,w2;
	for(int i=1;i<=n;i++)scanf("%lld",&w[i]);
	for(int i=1,x,y;i<n;i++)scanf("%d%d%lld%lld",&x,&y,&w1,&w2),add(x,y,w1,w2),add(y,x,w1,w2);
	dfs1(1,0),dfs2(1,0),dfs(1,0);
	for(int i=1;i<19;i++)for(int x=1;x<=n;x++)
		fa[x][i]=fa[fa[x][i-1]][i-1],f[x][i]=f[x][i-1]*f[fa[x][i-1]][i-1];
	scanf("%d",&Q);for(int x,y;Q--;printf("%lld\n",get_ans(x,y)))scanf("%d%d",&x,&y);
}