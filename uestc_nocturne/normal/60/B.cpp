#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int vis[20][20][20],n,m,K;
char map[20][20][20];
bool check(int x,int y,int z)
{
	if(x>K||x<1)return false;
	if(y>n||y<1)return false;
	if(z>m||z<1)return false;
	if(vis[x][y][z]==1)return false;
	if(map[x][y][z]=='#')return false;
	return true;
}
int dx[]={1,-1,0,0,0,0};
int dy[]={0,0,1,-1,0,0};
int dz[]={0,0,0,0,1,-1};
int i,j,k,top,tail;
struct Node{int x,y,z;}q[20*20*20];
int nx,ny,nz,tx,ty,tz,x,y,num;
int main()
{
	scanf("%d%d%d",&K,&n,&m);
	for(i=1;i<=K;i++)
	for(j=1;j<=n;j++)
	for(k=1;k<=m;k++)
	vis[i][j][k]=0;
	for(i=1;i<=K;i++)
	for(j=1;j<=n;j++)
	scanf("%s",map[i][j]+1);
	scanf("%d%d",&x,&y);
	top=0;tail=1;
	q[1].x=1;q[1].y=x;q[1].z=y;
	vis[1][x][y]=1;num=1;
	while(top<tail)
	{
		top++;
		nx=q[top].x;
		ny=q[top].y;
		nz=q[top].z;
	//	printf("%d %d %d %d\n",top,nx,ny,nz);
		for(i=0;i<6;i++)
		{
			tx=nx+dx[i];
			ty=ny+dy[i];
			tz=nz+dz[i];
			if(check(tx,ty,tz))
			{
				num++;
				tail++;
				vis[tx][ty][tz]=1;
				q[tail].x=tx;
				q[tail].y=ty;
				q[tail].z=tz;
			}
		}
	}
	printf("%d\n",num);
}