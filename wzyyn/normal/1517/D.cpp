#include<bits/stdc++.h>
using namespace std;

const int N=505;
int n,m,K;
int R[N][N],D[N][N];
int f[N][N][11];
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for (int i=1;i<=n;i++)
		for (int j=1;j<m;j++)
			scanf("%d",&R[i][j]);
	for (int i=1;i<n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&D[i][j]);
	if (K&1){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++)
				printf("-1 ");
			puts("");
		}
		return 0;
	}
	K/=2;
	memset(f,60,sizeof(f));
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			f[i][j][0]=0;
	for (int i=0;i<=K;i++)
		for (int j=0;j<=K-i-1;j++)
			for (int x=1;x<=n;x++)
				for (int y=1;y<=m;y++){
					if (y!=1) f[x][y][i+j+1]=min(f[x][y][i+j+1],f[x][y][i]+f[x][y-1][j]+R[x][y-1]);
					if (y!=m) f[x][y][i+j+1]=min(f[x][y][i+j+1],f[x][y][i]+f[x][y+1][j]+R[x][y  ]);
					if (x!=1) f[x][y][i+j+1]=min(f[x][y][i+j+1],f[x][y][i]+f[x-1][y][j]+D[x-1][y]);
					if (x!=n) f[x][y][i+j+1]=min(f[x][y][i+j+1],f[x][y][i]+f[x+1][y][j]+D[x  ][y]);
				}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++)
			printf("%d ",2*f[i][j][K]);
		puts("");
	}
}