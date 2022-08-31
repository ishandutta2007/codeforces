#include<stdio.h>
typedef unsigned u;
char of[9],cmd[9];
int main()
{
	u x,y=-1;
	scanf("%u%s%s",&x,of,cmd);
	if(*cmd=='w')
	{
		if(x==5||x==6)y=53;
		else y=52;
	}
	else if(*cmd=='m')
	{
		if(x<30)y=12;
		else if(x<31)y=11;
		else y=7;
	}
	printf("%u\n",y);
	return 0;
}