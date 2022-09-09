#include <stdio.h>
int Matrix[11][101][101];
int min(int a, int b)
{
	if(a>b) return b;
	else return a;
}
int main()
{
	int n,q,c,i,x,y,s,j,k;
	scanf("%i%i%i",&n,&q,&c);
	for(i=0;i<n;i++)
	{
		scanf("%i%i%i",&x,&y,&s);
		for(j=0;j<=10;j++)
		{
			Matrix[j][x][y]+=(s+j)%(c+1);//min(c,s+j);
		}
	}
	for(k=0;k<=10;k++)
	{
		for(i=1;i<=100;i++)
		{
			for(j=1;j<=100;j++)
			{
				Matrix[k][i][j]+=Matrix[k][i-1][j]+Matrix[k][i][j-1]-Matrix[k][i-1][j-1];
			}
		}
	}
	int t,x1,y1,x2,y2;
	for(i=0;i<q;i++)
	{
		scanf("%i%i%i%i%i",&t,&x1,&y1,&x2,&y2);
		x1--;
		y1--;
		//t=min(t,10);
		t=t%(c+1);
		int sol=Matrix[t][x2][y2]-Matrix[t][x1][y2]-Matrix[t][x2][y1]+Matrix[t][x1][y1];
		printf("%i\n",sol);
	}
	return 0;
}