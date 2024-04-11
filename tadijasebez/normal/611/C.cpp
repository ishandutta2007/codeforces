#include <stdio.h>
const int N=505;
int M1[N][N],M2[N][N];
char Matrix[N][N];
int Get1(int x1, int y1, int x2, int y2)
{
	x1--;
	y1--;
	return M1[x2][y2]+M1[x1][y1]-M1[x2][y1]-M1[x1][y2];
}
int Get2(int x1, int y1, int x2, int y2)
{
	x1--;
	y1--;
	return M2[x2][y2]+M2[x1][y1]-M2[x2][y1]-M2[x1][y2];
}
void Print(int n, int m, int M[N][N])
{
	int i,j;
	printf("\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++) printf("%i ",M[i][j]);
		printf("\n");
	}
	printf("\n");
}
int main()
{
	int n,m,q,i,j,x1,x2,y1,y2;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",Matrix[i]+1);
	for(i=1;i<=n;i++)
		for(j=1;j<=m-1;j++)
			if(Matrix[i][j]=='.' && Matrix[i][j+1]=='.') M1[i][j]=1;
	//Print(n,m,M1);
	for(i=1;i<=n;i++)
		for(j=1;j<=m-1;j++)
			M1[i][j]+=M1[i-1][j]+M1[i][j-1]-M1[i-1][j-1];
	//Print(n,m,M1);
	for(i=1;i<=n-1;i++)
		for(j=1;j<=m;j++)
			if(Matrix[i][j]=='.' && Matrix[i+1][j]=='.') M2[i][j]=1;
	//Print(n,m,M2);
	for(i=1;i<=n-1;i++)
		for(j=1;j<=m;j++)
			M2[i][j]+=M2[i-1][j]+M2[i][j-1]-M2[i-1][j-1];
	//Print(n,m,M2);
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i %i %i",&x1,&y1,&x2,&y2);
		printf("%i\n",Get1(x1,y1,x2,y2-1)+Get2(x1,y1,x2-1,y2));
	}
	return 0;
}