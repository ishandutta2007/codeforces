#include<stdio.h>
typedef unsigned u;
int main()
{
	char c;u x=0,y=0,min=-1;
	while((c=getchar())<=' ');
	do
	{
		if(c=='#'){++y;min=-1;}
		if(c=='(')++x;
		else
		{
			if(x==0){printf("-1\n");return 0;}
			--x;
		}
		if(min>x)min=x;
	}
	while((c=getchar())>' ');
	if(x!=min){printf("-1\n");return 0;}
	while(--y)printf("1\n");
	printf("%u\n",x+1);
	return 0;
}