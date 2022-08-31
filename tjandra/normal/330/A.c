#include<stdio.h>
typedef unsigned u;
u v[10],h[10];
int main()
{
	u i,j,n,x,y,r=0;
	char c;
	scanf("%u%u",&i,&j);n=i;
	for(x=0;x<i;x++)for(y=0;y<j;y++)
	{
		while((c=getchar())<' ');
		if(c=='S'){v[x]++;h[y]++;}
	}
	for(x=0;x<i;x++)if(v[x]==0)r+=j,n--;
	for(y=0;y<j;y++)if(h[y]==0)r+=n;
	printf("%u\n",r);
	return 0;
}