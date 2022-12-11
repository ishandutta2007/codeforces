#include<bits/stdc++.h>
#define maxn 205
#define fi first
#define se second
using namespace std;
int n,m,q;
int a[maxn][maxn],ind[maxn][maxn],fx[maxn][maxn],fy[maxn][maxn];
int fa[maxn*maxn],bel[maxn*maxn],cnt,qry[maxn*maxn];
pair<int,int> cyc[maxn*maxn];
vector<int> g[maxn*maxn];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int sta[maxn*maxn],stb[1000005];
int dx[maxn],dy[maxn];
int vis[maxn][maxn];
char str[1000005];
bool isvalid(int x,int y)
{
	if(x<1)return 0;
	if(x>n)return 0;
	if(y<1)return 0;
	if(y>m)return 0;
	return 1;
}
int ID(int x,int y)
{
	return (x-1)*m+y;
}
int mind,vv[maxn*maxn];
void dfs(int u,int d)
{
	int x=(u-1)/m+1,y=u-(x-1)*m;
	if(str[d]-'0'==a[x][y])d--;
	mind=min(mind,d);
	vv[u]=1;
	for(int v:g[u])if(!vv[v])dfs(v,d);
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)scanf("%1d",&a[i][j]);
	for(int i=0;i<=9;++i)scanf("%d%d",&dx[i],&dy[i]);
	for(int i=1;i<=n*m;++i)fa[i]=i;
	for(int x=1;x<=n;++x)
	{
		for(int y=1;y<=m;++y)
		{
			int d=a[x][y];
			int nx=x+dx[d],ny=y+dy[d];
			if(!isvalid(nx,ny))nx=x,ny=y;
			ind[nx][ny]++;
			fx[x][y]=nx;fy[x][y]=ny;
			g[ID(nx,ny)].push_back(ID(x,y));
			int u=find(ID(x,y)),v=find(ID(nx,ny));
			if(u!=v)fa[u]=v;
		}
	}
	for(int x=1;x<=n;++x)
	{
		for(int y=1;y<=m;++y)
		{
			if(find(ID(x,y))==ID(x,y))bel[ID(x,y)]=++cnt;
		}
	}
	for(int x=1;x<=n;++x)
	{
		for(int y=1;y<=m;++y)
		{
			if(!bel[ID(x,y)])bel[ID(x,y)]=bel[find(ID(x,y))];
		}
	}
	for(int x=1;x<=n;++x)
	{
		for(int y=1;y<=m;++y)if(find(ID(x,y))==ID(x,y))
		{
			int id=bel[ID(x,y)];
			int ux=x,uy=y;
			while(1)
			{
				vis[ux][uy]++;
				int nx=fx[ux][uy],ny=fy[ux][uy];
				if(vis[nx][ny]==1)
				{
					ux=nx;uy=ny;
					break;
				}
				ux=nx,uy=ny;
			}
			while(1)
			{
				vis[ux][uy]++;
				sta[id]|=(1<<a[ux][uy]);
				int nx=fx[ux][uy],ny=fy[ux][uy];
				if(vis[nx][ny]==2)
				{
					ux=nx;uy=ny;
					break;
				}
				ux=nx,uy=ny;
			}
			cyc[id]=make_pair(ux,uy);
		}
	}
	while(q--)
	{
		memset(qry,0,sizeof(qry));
		memset(vv,0,sizeof(vv));
		scanf("%s",str+1);
		int len=strlen(str+1);
		stb[len+1]=0;
		for(int i=len;i>=1;--i)stb[i]=(stb[i+1]|(1<<(str[i]-'0')));
		bool yes=0;
		for(int x=1;x<=n;++x)
		{
			for(int y=1;y<=m;++y)if(!qry[bel[ID(x,y)]])
			{
				int id=bel[ID(x,y)];
				qry[id]=1;
				int ux=cyc[id].fi,uy=cyc[id].se;
				int l=1,r=len,ans=len+1;
				while(l<=r)
				{
					int mid=(l+r)>>1;
					if((sta[id]&stb[mid])==stb[mid])ans=mid,r=mid-1;
					else l=mid+1;
				}
				ans--;mind=ans;
				dfs(ID(ux,uy),ans);
				if(!mind)
				{
					yes=1;
					break;
				}
			}
			if(yes)break;
		}
		if(yes)puts("YES");
		else puts("NO");
	}
}
/*
8 1 1
5
8
8
0
4
4
1
2
7 1
-8 1
3 1
6 -1
6 -1
2 0
8 1
-7 -1
2 0
-3 0
844
*/