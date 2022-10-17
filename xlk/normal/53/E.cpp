#include<stdio.h>
int n,m,t,x,y,z;
int a[20][20],f[1050][1050];
int main()
{
	scanf("%d%d%d",&n,&m,&t);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y),x--,y--;
		a[x][y]=a[y][x]=f[1<<x|1<<y][1<<x|1<<y]=1;
	}
	for(int i=0;i<1<<n;i++)
		for(int j=i;j;--j&=i)
			if(f[i][j])
				for(x=0;x<n;x++)
					for(y=0;y<n;y++)
						if(i>>x&1&&~i>>y&1&&a[x][y])
						{
							int u=j&~(1<<x)|1<<y;
							if(!(u>>y+1))
								f[i|1<<y][u]+=f[i][j];
						}
	for(int i=0;i<1<<n;i++)
		if(__builtin_popcount(i)==t)
			z+=f[(1<<n)-1][i];
	printf("%d\n",z);
	return 0;
}