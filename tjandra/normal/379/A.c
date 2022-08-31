#include<stdio.h>
typedef unsigned u;
int main()
{
	u x,y,r=0,s=0;
	scanf("%u%u",&x,&y);	
	do{r+=x;x+=s;s=x%y;}while(x/=y);
	printf("%u\n",r);
	return 0;
}