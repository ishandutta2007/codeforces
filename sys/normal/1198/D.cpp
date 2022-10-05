#include <bits/stdc++.h>
using namespace std;
const int Maxn=55; 
char str[Maxn][Maxn];
int n,f[Maxn][Maxn][Maxn][Maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s",str[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j][i][j]=(str[i][j]=='#');
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i>1||j>1)
				for(int p=1;i+p-1<=n;p++)
					for(int q=1;j+q-1<=n;q++)
					{
						int x=i+p-1,y=j+q-1;
						f[p][q][x][y]=max(i,j);
						for(int k=p;k<=x;k++)
							f[p][q][x][y]=min(f[p][q][x][y],f[p][q][k][y]+f[k+1][q][x][y]);
						for(int k=q;k<=y;k++)
							f[p][q][x][y]=min(f[p][q][x][y],f[p][q][x][k]+f[p][k+1][x][y]);
					}
	printf("%d",f[1][1][n][n]);
	return 0;
}