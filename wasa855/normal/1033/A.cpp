#include<bits/stdc++.h>
using namespace std;
bool ok[1005][1005];
bool used[1005][1005];
int dx[]={0,0,0,1,-1,1,1,-1,-1};
int dy[]={0,1,-1,1,1,-1,0,0,-1};
int sx,sy,fx,fy;
int n;
void dfs(int nx,int ny)
{
	used[nx][ny]=true;
	if(nx==fx&&ny==fy)
	{
		cout<<"YES\n";
		exit(0);
	}
	for(int i=1;i<=8;i++)
	{
		int tx=nx+dx[i];
		int ty=ny+dy[i];
		if(tx<1||ty<1||tx>n||ty>n)
		{
			continue;
		}
		if(ok[tx][ty]==false&&used[tx][ty]==false)
		{
			dfs(tx,ty);
		}
	}
}
int main()
{
	cin>>n;
	int a,b;
	cin>>a>>b;
	int l=min(a,b);
	for(int i=1;i<=n;i++)
	{
		ok[i][b]=true;
		ok[a][i]=true;
	}
	int x=a,y=b;
	while(x<=n&&y<=n)
	{
		ok[x][y]=true;
		x++;
		y++;
//		printf("%d %d\n",x,y);
	}
	x=a,y=b;
	while(x>0&&y>0&&x<=n&&y<=n)
	{
		ok[x][y]=true;
		x--;
		y--;
//		printf("%d %d\n",x,y);
	}
	x=a,y=b;
	while(x>0&&y>0&&x<=n&&y<=n)
	{
		ok[x][y]=true;
		x--;
		y++;
//		printf("%d %d\n",x,y);
	}
	x=a,y=b;
	while(x>0&&y>0&&x<=n&&y<=n)
	{
		ok[x][y]=true;
		x++;
		y--;
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			printf("%d ",ok[i][j]);
//		}
//		cout<<"\n";
//	}
	cin>>sx>>sy>>fx>>fy;
	dfs(sx,sy);
	cout<<"NO\n";
	return 0;
}