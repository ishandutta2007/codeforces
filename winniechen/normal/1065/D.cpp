#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 105
struct node
{
	int x,y;
	node(){;}
	node(int a,int b){x=a,y=b;}
	bool operator < (const node &a) const {return x==a.x?y<a.y:x<a.x;}
	node operator + (const int &a) const {return node(x+a,y);}
}f[3][N][N];
int map[3][N][N],n,p[N],vis[3][N];
int dx[]={-2,-1,1,2,2,1,-1,-2};
int dy[]={-1,-2,-2,-1,1,2,2,1};
int main()
{
	scanf("%d",&n);int tot=n*n;memset(map,0x3f,sizeof(map));memset(f,0x3f,sizeof(f));
	for(int i=1,x;i<=n;i++)
		for(int j=1;j<=n;j++)scanf("%d",&x),p[x]=(i-1)*n+j;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<8;k++)
			{
				int tx=i+dx[k],ty=j+dy[k];
				if(tx<=0||tx>n||ty<=0||ty>n)continue;
				map[0][(i-1)*n+j][(tx-1)*n+ty]=1;
			}
			for(int k=1;k<=n;k++)
			{
				map[1][(i-1)*n+j][(i-1)*n+k]=1;
				map[1][(i-1)*n+j][(k-1)*n+j]=1;
				if(j-i+k>0&&j-i+k<=n)map[2][(i-1)*n+j][(k-1)*n+(j-i+k)]=1;
				if(i-k+j>0&&j-k+i<=n)map[2][(i-1)*n+j][(k-1)*n+(i+j-k)]=1;
			}
			for(int t=0;t<3;t++)map[t][(i-1)*n+j][(i-1)*n+j]=0;
		}
	for(int t=0;t<3;t++)
		for(int k=1;k<=tot;k++)
			for(int i=1;i<=tot;i++)
				for(int j=1;j<=tot;j++)
					map[t][i][j]=min(map[t][i][k]+map[t][k][j],map[t][i][j]);
	// for(int i=1;i<=n;i++)
	// 	for(int j=1;j<=n;j++)
	// 		for(int k=1;k<=n;k++,puts(""))
	// 			for(int l=1;l<=n;l++)
	// 				printf("%d ",map[2][(i-1)*n+j][(k-1)*n+l]);
	f[0][p[1]][1]=f[1][p[1]][1]=f[2][p[1]][1]=node(0,0);
	for(int i=2;i<=tot;i++)
	{
		for(int t=0;t<3;t++)
		{
			for(int k=1;k<=tot;k++)
				for(int l=0;l<3;l++)
					// f[t][p[i]][i]=min(f[l][k][i-1]+map[t][k][p[i]]+(l!=t),f[t][p[i]][i]);
					f[t][p[i]][i]=min(node(f[l][k][i-1].x+map[t][k][p[i]]+(l!=t),f[l][k][i-1].y+(l!=t)),f[t][p[i]][i]);
			// for(int j=1;j<=tot;j++)
			// 	f[t][j][i]=min(node(f[t][p[i]][i].x+map[t][p[i]][j],f[t][p[i]][i].y),f[t][j][i]);
		}memset(vis,0,sizeof(vis));
		for(int cas=1;cas<=tot*3;cas++)
		{
			node mn=node(0x3f3f3f3f,0x3f3f3f3f);
			int p,t;
			for(int j=1;j<=tot;j++)for(int l=0;l<3;l++)
				if(!vis[l][j]&&f[l][j][i]<mn)mn=f[l][j][i],p=j,t=l;
			vis[t][p]=1;
			for(int j=1;j<=tot;j++)for(int l=0;l<3;l++)if(!vis[l][j])
				f[l][j][i]=min(node(f[t][p][i].x+map[l][p][j]+(l!=t),f[t][p][i].y+(l!=t)),f[l][j][i]);
		}
	}
	node ans=min(min(f[0][p[tot]][tot],f[1][p[tot]][tot]),f[2][p[tot]][tot]);
	printf("%d %d\n",ans.x,ans.y);
}