#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=1050;
int b[N][N],a[4][N][N];
char s[N];
int p[4];
int min(int a, int b){ return a>b?b:a;}
int Try(int n)
{
	int c[2][2],i,j;
	for(i=0;i<2;i++) for(j=0;j<2;j++) c[i][j]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			c[(i+j)&1][b[i][j]]++;
		}
	}
	return min(c[0][0]+c[1][1],c[0][1]+c[1][0]);
}
int main()
{
	int n,i,j,k;
	scanf("%i",&n);
	for(k=0;k<4;k++)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(j=1;j<=n;j++) a[k][i][j]=(s[j]=='1');
		}
	}
	int sol=1000000000;
	for(i=0;i<4;i++) p[i]=i;
	do
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				b[i][j]=a[p[0]][i][j];
				b[i+n][j]=a[p[1]][i][j];
				b[i][j+n]=a[p[2]][i][j];
				b[i+n][j+n]=a[p[3]][i][j];
			}
		}
		sol=min(sol,Try(n*2));
	}while(next_permutation(p,p+4));
	printf("%i\n",sol);
	return 0;
}