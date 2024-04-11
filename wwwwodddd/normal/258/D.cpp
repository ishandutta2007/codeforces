#include<stdio.h>
int a[1000],n,m,x,y;
double p[1000][1000],z;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			p[i][j]=a[i]>a[j];
	for(;m--;)
	{
		scanf("%d %d",&x,&y),x--,y--;
		p[x][y]=p[y][x]=.5;
		for(int i=0;i<n;i++)
			if(i!=x&&i!=y)
			{
				p[i][x]=p[i][y]=(p[i][x]+p[i][y])*.5;
				p[x][i]=p[y][i]=(p[x][i]+p[y][i])*.5;
			}
	}
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			z+=p[i][j];
	printf("%.9f",z);
	return 0;
}