#include<stdio.h>
typedef unsigned u;
int main()
{
	u x,y,i,j,r;char c;
	scanf("%u%u",&x,&y);
	for(i=0;i<x;i++)for(j=0;j<y;j++)
	{
		while((c=getchar())<'0');
		if(c=='1')if(i==0||i==x-1||j==0||j==y-1)
		{
			printf("2\n");
			return 0;
		}
	}
	printf("4\n",r);
	return 0;
}