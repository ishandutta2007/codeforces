#include<stdio.h>
#include<stdlib.h>
typedef unsigned u;
int coX[100000],coY[100000];
int F(const void *x,const void *y)
{
	u d1x,d1y,d2x,d2y;
	d1x=coX[*(u*)x]>0?coX[*(u*)x]:-coX[*(u*)x];
	d2x=coX[*(u*)y]>0?coX[*(u*)y]:-coX[*(u*)y];
	d1y=coY[*(u*)x]>0?coY[*(u*)x]:-coY[*(u*)x];
	d2y=coY[*(u*)y]>0?coY[*(u*)y]:-coY[*(u*)y];
	if(d1x>d2x)return -1;
	if(d1x<d2x)return 1;
	if(d1y>d2y)return -1;
	if(d1y<d2y)return 1;
	return 0;
}
u con[100000];
int main()
{
	u n,t=0,k=0;
	for(scanf("%u",&n);t<n;t++)
	{
		scanf("%i%i",coX+t,coY+t);con[t]=t;
		k+=1+(coX[t]!=0)+(coY[t]!=0);
	}
	printf("%u\n",k<<1);qsort(con,n,sizeof(u),F);
	while(n--)
	{
		if(coX[con[n]]<0)printf("1 %i L\n",-coX[con[n]]);
		else if(coX[con[n]]>0)printf("1 %i R\n",coX[con[n]]);
		if(coY[con[n]]<0)printf("1 %i D\n",-coY[con[n]]);
		else if(coY[con[n]]>0)printf("1 %i U\n",coY[con[n]]);
		printf("2\n");
		if(coY[con[n]]<0)printf("1 %i U\n",-coY[con[n]]);
		else if(coY[con[n]]>0)printf("1 %i D\n",coY[con[n]]);
		if(coX[con[n]]<0)printf("1 %i R\n",-coX[con[n]]);
		else if(coX[con[n]]>0)printf("1 %i L\n",coX[con[n]]);
		printf("3\n");
	}
	return 0;
}