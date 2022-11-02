#include <stdio.h>
#include <memory.h>

int f[22][6][6][11][11];
int n,m;

int main(){
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	memset(f,0,sizeof(f));
	for (int i=1;i<5;i++)
		for (int j=1;j<5;j++)
			if (i!=j)f[2][i][j][0][0]++;
	for (int i=2;i<n;i++)
		for (int x=1;x<5;x++)
			for (int y=1;y<5;y++)
				for (int o1=0;o1<=m;o1++)
					for (int o2=0;o2<m;o2++)
						if (f[i][x][y][o1][o2]>0)
							for (int z=1;z<5;z++){
								if (z==y)continue;
								int n1=o1,n2=o2;
								if (y>x&&y>z)n1++;
								if (y<x&&y<z)n2++;
								if (n1>m)continue;
								if (n2>=m)continue;
								f[i+1][y][z][n1][n2]+=f[i][x][y][o1][o2];
							}
	int res=0;
	for (int x=1;x<5;x++)
		for (int y=1;y<5;y++)
			res+=f[n][x][y][m][m-1];
	printf("%d\n",res);
}