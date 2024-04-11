#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n,m,a[2005][2005],num[2][2005][2005],stx,sty,x,y;
bool flag[2005][2005];
queue<int>qx,qy;
inline int read()
{
	char c=getchar();
	while(c!='*'&&c!='.')c=getchar();
	return c=='*';
}
void bfs()
{
	qx.push(stx);
	qy.push(sty);
	memset(num,0x3f,sizeof(num));
	num[0][stx][sty]=num[1][stx][sty]=0;
	flag[stx][sty]=1;
	while(!qx.empty())
	{
		int x=qx.front();
		int y=qy.front();
		qx.pop();
		qy.pop();
		if(x+1<=n&&!a[x+1][y]&&(num[0][x][y]<num[0][x+1][y]||num[1][x][y]<num[1][x+1][y]))
		{
			num[0][x+1][y]=num[0][x][y];
			num[1][x+1][y]=num[1][x][y];
			flag[x+1][y]=1;
			qx.push(x+1);
			qy.push(y);
		}
		if(x-1>=1&&!a[x-1][y]&&(num[0][x][y]<num[0][x-1][y]||num[1][x][y]<num[1][x-1][y]))
		{
			num[0][x-1][y]=num[0][x][y];
			num[1][x-1][y]=num[1][x][y];
			flag[x-1][y]=1;
			qx.push(x-1);
			qy.push(y);
		}
		if(y+1<=m&&!a[x][y+1]&&(num[0][x][y]<num[0][x][y+1]||num[1][x][y]+1<num[1][x][y+1]))
		{
			num[0][x][y+1]=num[0][x][y];
			num[1][x][y+1]=num[1][x][y]+1;
			flag[x][y+1]=1;
			qx.push(x);
			qy.push(y+1);
		}
		if(y-1>=1&&!a[x][y-1]&&(num[0][x][y]+1<num[0][x][y-1]||num[1][x][y]<num[1][x][y-1]))
		{
			num[0][x][y-1]=num[0][x][y]+1;
			num[1][x][y-1]=num[1][x][y];
			flag[x][y-1]=1;
			qx.push(x);
			qy.push(y-1);
		}
	}
}
int main()
{
	scanf("%d%d%d%d%d%d",&n,&m,&stx,&sty,&x,&y);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    a[i][j]=read();
	bfs();
	int ans=0;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		  printf("%d ",num[1][i][j]);
//		printf("\n");
//	}
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    if(num[0][i][j]<=x&&num[1][i][j]<=y)
	      ans++;
	printf("%d\n",ans);
	return 0;
}