#include<stdio.h>
#include<stdlib.h>
typedef unsigned u;
char cmd[9];
int main()
{
	u q,l,x=0;
	for(scanf("%u",&q);q--;)
	{
		scanf("%u%s",&l,cmd);
		if((*cmd=='W'||*cmd=='E')&&(!x||x==20000))goto NO;
		if(*cmd=='N')x-=l;
		if(*cmd=='S')x+=l;
		if(x>20000)goto NO;
	}
	printf(x?"NO\n":"YES\n");
	return 0;
	NO:;printf("NO\n");
	return 0;
}