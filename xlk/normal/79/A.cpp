#include<stdio.h>
int x,y;
int A()
{
	if(x>1&&y>1)
		x-=2,y-=2;
	else if(x>0&&y>11)
		x--,y-=12;
	else if(y>21)
		y-=22;
	else
	{
		puts("Hanako");
		return 1;
	}
	return 0;
}
int B()
{
	if(y>21)
		y-=22;
	else if(x>0&&y>11)
		x--,y-=12;
	else if(x>1&&y>1)
		x-=2,y-=2;
	else
	{
		puts("Ciel");
		return 1;
	}
	return 0;	
}
int main()
{
	scanf("%d %d",&x,&y);
	for(;;)
		if(A()||B())
			break;
	return 0;
}