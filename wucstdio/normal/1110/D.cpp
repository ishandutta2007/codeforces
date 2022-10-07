#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,num[1000005],g[10][10],f[10][10];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		num[x]++;
	}
	for(int i=0;i<7;i++)
	  for(int j=0;j<7;j++)
	    g[i][j]=f[i][j]=-2147483647;
	g[0][0]=0;
	for(int i=1;i<=m;i++)
	{
		for(int x=0;x<7;x++)
		for(int y=0;y<7;y++)
		{
//			if(f[i-1][x][y]<0)printf("-1 ");
//			else printf("%d ",f[i-1][x][y]);
			int xx=x,yy=y,nn=num[i];
			int d=0;
			while(min(xx,min(yy,nn))>=0)
			{
				f[yy][nn%3]=max(f[yy][nn%3],g[x][y]+nn/3+d);
				if(nn-nn%3>=3)
				  f[yy][nn%3+3]=max(f[yy][nn%3+3],g[x][y]+nn/3+d-1);
				if(nn-nn%3>=6)
				  f[yy][nn%3+6]=max(f[yy][nn%3+6],g[x][y]+nn/3+d-2);
				xx--,yy--,nn--;
				d++;
			}
		}
		for(int x=0;x<7;x++)
		  for(int y=0;y<7;y++)
		    g[x][y]=f[x][y],f[x][y]=-2147483647;
//		printf("\n");
	}
	int ans=0;
	for(int i=0;i<7;i++)
	  for(int j=0;j<7;j++)
	    ans=max(ans,g[i][j]);
	printf("%d\n",ans);
	return 0;
}