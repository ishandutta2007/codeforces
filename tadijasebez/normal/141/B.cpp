#include <stdio.h>
int main()
{
	int a,x,y;
	scanf("%i %i %i",&a,&x,&y);
	if(y%a==0)
	{
		printf("-1\n");
		return 0;
	}
	if(y<a)
	{
		if(x<(a+1)/2 && x>-(a+1)/2) printf("1\n");
		else printf("-1\n");
		return 0;
	}
	y-=a;
	int b=y/(2*a);
	int c=y%(2*a);
	if(c<a)
	{
		if(x<(a+1)/2 && x>-(a+1)/2) printf("%i\n",b*3+2);
		else printf("-1\n");
	}
	else
	{
		if(x<a && x>0) printf("%i\n",b*3+4);
		else if(x>-a && x<0) printf("%i\n",b*3+3);
		else printf("-1\n");
	}
	return 0;
}