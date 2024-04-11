#include<stdio.h>
int d[120][120];
double c[120][120];
int n,m,x,y;
double z,mx;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				d[i][j]=0xffff;
			else
				c[i][j]=1;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		d[x][y]=c[x][y]=d[y][x]=c[y][x]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j&&j!=k&&k!=i)
					if(d[i][j]>d[i][k]+d[k][j])
					{
						d[i][j]=d[i][k]+d[k][j];
						c[i][j]=c[i][k]*c[k][j];
					}
					else if(d[i][j]==d[i][k]+d[k][j])
						c[i][j]+=c[i][k]*c[k][j];
	for(int i=1;i<=n;i++)
	{
		z=0;
		for(int j=1;j<=n;j++)
			if(d[i][j]==1)
				if(d[1][i]+1+d[j][n]==d[1][n])
					z+=c[1][i]*c[j][n];
				else if(d[1][j]+1+d[i][n]==d[1][n])
					z+=c[1][j]*c[i][n];
		if(mx<z)
			mx=z;
	}
	printf("%.20f",mx/c[1][n]);
	return 0;
}