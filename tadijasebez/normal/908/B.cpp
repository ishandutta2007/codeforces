#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=55;
int Move[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
char Base[N][N];
char dir[N*2];
int perm[4],sol;
void Try(int x, int y, int ex, int ey, int q)
{
	int i;
	for(i=0;i<q;i++)
	{
		x+=Move[perm[dir[i]-'0']][0];
		y+=Move[perm[dir[i]-'0']][1];
		//printf("%i %i\n",x,y);
		if(Base[x][y]!='.') return;
		if(x==ex && y==ey)
		{
			sol++;
			return;
		}
	}
	if(x!=ex || y!=ey) return;
	sol++;
}
int main()
{
	int n,m,i,j,x,y,ex,ey;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%s",Base[i]+1);
		for(j=1;j<=m;j++)
		{
			if(Base[i][j]=='S') x=i,y=j,Base[i][j]='.';
			if(Base[i][j]=='E') ex=i,ey=j,Base[i][j]='.';
		}
	}
	scanf("%s",&dir);
	int q=strlen(dir);
	//printf("%i %i %i %i %i\n",x,y,ex,ey,q);
	for(i=0;i<4;i++) perm[i]=i;
	do
	{
		//printf(":D");
		Try(x,y,ex,ey,q);
	}while(next_permutation(perm,perm+4));
	printf("%i\n",sol);
	return 0;
}