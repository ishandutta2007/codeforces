#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};
int n,edgenum,x[1005][1005],y[1005][1005],dep[1005][1005];
bool flag[1005][1005];
char ans[1005][1005];
queue<int>qx,qy;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    scanf("%d%d",&x[i][j],&y[i][j]);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(x[i][j]==i&&y[i][j]==j)
		{
			flag[i][j]=1;
			qx.push(i),qy.push(j);
			ans[i][j]='X';
			while(!qx.empty())
			{
				int nowx=qx.front();
				qx.pop();
				int nowy=qy.front();
				qy.pop();
				for(int k=0;k<4;k++)
				{
					int xx=nowx+dx[k];
					int yy=nowy+dy[k];
					if(xx>=1&&xx<=n&&yy>=1&&yy<=n&&x[xx][yy]==i&&y[xx][yy]==j&&!flag[xx][yy])
					{
						flag[xx][yy]=1;
						dep[xx][yy]=dep[nowx][nowy]+1;
						if(k==0)ans[xx][yy]='U';
						if(k==1)ans[xx][yy]='D';
						if(k==2)ans[xx][yy]='L';
						if(k==3)ans[xx][yy]='R';
						qx.push(xx);
						qy.push(yy);
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(x[i][j]!=-1&&!flag[i][j])
		{
			printf("INVALID\n");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(i!=n&&!flag[i][j]&&x[i][j]==-1&&x[i+1][j]==-1)
		{
			qx.push(i),qy.push(j);
			qx.push(i+1),qy.push(j);
			ans[i][j]='D';
			ans[i+1][j]='U';
			flag[i][j]=flag[i+1][j]=1;
			while(!qx.empty())
			{
				int nowx=qx.front();
				qx.pop();
				int nowy=qy.front();
				qy.pop();
				for(int k=0;k<4;k++)
				{
					int xx=nowx+dx[k];
					int yy=nowy+dy[k];
					if(xx>=1&&xx<=n&&yy>=1&&yy<=n&&x[xx][yy]==-1&&!flag[xx][yy])
					{
						flag[xx][yy]=1;
						dep[xx][yy]=dep[nowx][nowy]+1;
						if(k==0)ans[xx][yy]='U';
						if(k==1)ans[xx][yy]='D';
						if(k==2)ans[xx][yy]='L';
						if(k==3)ans[xx][yy]='R';
						qx.push(xx);
						qy.push(yy);
					}
				}
			}
		}
		if(j!=n&&!flag[i][j]&&x[i][j]==-1&&x[i][j+1]==-1)
		{
			qx.push(i),qy.push(j);
			qx.push(i),qy.push(j+1);
			ans[i][j]='R';
			ans[i][j+1]='L';
			flag[i][j]=flag[i][j+1]=1;
			while(!qx.empty())
			{
				int nowx=qx.front();
				qx.pop();
				int nowy=qy.front();
				qy.pop();
				for(int k=0;k<4;k++)
				{
					int xx=nowx+dx[k];
					int yy=nowy+dy[k];
					if(xx>=1&&xx<=n&&yy>=1&&yy<=n&&x[xx][yy]==-1&&!flag[xx][yy])
					{
						flag[xx][yy]=1;
						dep[xx][yy]=dep[nowx][nowy]+1;
						if(k==0)ans[xx][yy]='U';
						if(k==1)ans[xx][yy]='D';
						if(k==2)ans[xx][yy]='L';
						if(k==3)ans[xx][yy]='R';
						qx.push(xx);
						qy.push(yy);
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(!flag[i][j])
		{
			printf("INVALID\n");
			return 0;
		}
	}
	printf("VALID\n");
	for(int i=1;i<=n;i++)printf("%s\n",ans[i]+1);
	return 0;
}