#include <stdio.h>
const int N=5050;
int C[N],M[N][N],sol,s;
char Base[N][N];
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%s",Base[i]+1);
		for(j=1;j<=m;j++)
		{
			M[i][j]=M[i][j-1]*(Base[i][j]-'0')+Base[i][j]-'0';
		}
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++) C[M[j][i]]++;
		for(s=0,j=5000;j>0;j--) s+=C[j],sol=max(sol,s*j);
		for(j=1;j<=n;j++) C[M[j][i]]--;
	}
	printf("%i\n",sol);
	return 0;
}