#include <stdio.h>
const int N=69;
char Base[N][N];
bool vis[N][N];
int Move[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void DFS(int x, int y)
{
	vis[x][y]=true;
	int nx,ny,i;
	for(i=0;i<4;i++)
	{
		nx=x+Move[i][0];
		ny=y+Move[i][1];
		if(Base[nx][ny]=='#' && !vis[nx][ny]) DFS(nx,ny);
	}
}
int Cnt(int n, int m)
{
	int i,j,ret=0;
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) vis[i][j]=0;
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) if(!vis[i][j] && Base[i][j]=='#') ret++,DFS(i,j);
	return ret;
}
bool One(int n, int m)
{
	int i,j;
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) if(Base[i][j]=='#')
	{
		Base[i][j]='.';
		if(Cnt(n,m)>1) return true;
		Base[i][j]='#';
	}
	return false;
}
int main()
{
	int i,j,sum=0,n,m;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",Base[i]+1);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) sum+=Base[i][j]=='#';
	if(sum<3) printf("-1\n");
	else if(One(n,m)) printf("1\n");
	else printf("2\n");
	return 0;
}