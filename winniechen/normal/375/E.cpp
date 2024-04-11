#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 501
struct node{int to,next,val;}e[N<<1];short f[N][N][N],g[N][N];
int a[N],p[N],in[N],out[N],head[N],cnt,tims,n,m,ans,siz[N];
int dis[N][N],X;
void add(int x,int y,int z){e[cnt]=(node){y,head[x]};head[x]=cnt++;}
void dfs(int x,int from)
{
	in[x]=++tims;p[tims]=x;
	for(int i=head[x];i!=-1;i=e[i].next)if(e[i].to!=from)dfs(e[i].to,x);
	out[x]=tims;
}
void Floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
}
void DP(int x,int from)
{
	siz[x]=1;
	for(int i=1;i<=n;i++)if(x!=i&&dis[x][i]<=X)f[x][0][i]=0;f[x][1][x]=!a[x];
	for(int i=head[x];i!=-1;i=e[i].next)if(e[i].to!=from)
	{
		int to1=e[i].to;DP(to1,x);
		for(int j=0;j<=siz[x]+siz[to1];j++)memset(g[j],0x3f,sizeof(g[j]));
		for(int j=0;j<=siz[x]&&j<=m;j++)for(int k=0;k<=siz[to1]&&j+k<=m;k++)
		{
			short mn=0x3f3f;
			for(int l=in[to1];l<=out[to1];l++)mn=min(mn,f[to1][k][p[l]]);
			for(int l=1;l<=n;l++)g[j+k][l]=min(short(f[to1][k][l]+f[x][j][l]),g[j+k][l]);
			for(int l=1;l<in[to1];l++)g[j+k][p[l]]=min(g[j+k][p[l]],short(f[x][j][p[l]]+mn));
			for(int l=out[to1]+1;l<=n;l++)g[j+k][p[l]]=min(g[j+k][p[l]],short(f[x][j][p[l]]+mn));
		}siz[x]+=siz[to1];
		for(int j=0;j<=siz[x];j++)memcpy(f[x][j],g[j],sizeof(g[j]));
	}
}
int main()
{
	scanf("%d%d",&n,&X);memset(head,-1,sizeof(head));memset(f,0x3f,sizeof(f));memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),m+=a[i];
	for(int i=1,x,y,z;i<n;i++)scanf("%d%d%d",&x,&y,&z),add(x,y,z),add(y,x,z),dis[x][y]=dis[y][x]=z;
	Floyd();dfs(1,0);DP(1,0);ans=0x3f3f3f3f;
	for(int i=1;i<=n;i++)ans=min(ans,(int)f[1][m][i]);
	printf("%d\n",ans>n?-1:ans);
}