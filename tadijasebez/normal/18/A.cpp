#include <stdio.h>
struct Point
{
	int x,y;
	int operator + (const Point &b) const
	{
		return (x-b.x)*(x-b.x)+(y-b.y)*(y-b.y);
	}
} a,c,d;
int max(int a, int b)
{
	if(a>b) return a;
	else return b;
}
int max(int a, int b, int c)
{
	return max(a,max(b,c));
}
bool Check(Point a, Point b, Point c)
{
	if((a+b)==0) return false;
	if((b+c)==0) return false;
	if((a+c)==0) return false;
	return (max(a+b,b+c,a+c))==(((a+b)+(b+c)+(a+c))-max(a+b,b+c,a+c));
}
int main()
{
	scanf("%i %i %i %i %i %i",&a.x,&a.y,&c.x,&c.y,&d.x,&d.y);
	if(Check(a,c,d))
	{
		printf("RIGHT\n");
		return 0;
	}
	else
	{
		bool ok=false;
		a.x++;
		if(Check(a,c,d)) ok=true;
		a.x-=2;
		if(Check(a,c,d)) ok=true;
		a.x++;
		a.y++;
		if(Check(a,c,d)) ok=true;
		a.y-=2;
		if(Check(a,c,d)) ok=true;
		a.y++;
		c.x++;
		if(Check(a,c,d)) ok=true;
		c.x-=2;
		if(Check(a,c,d)) ok=true;
		c.x++;
		c.y++;
		if(Check(a,c,d)) ok=true;
		c.y-=2;
		if(Check(a,c,d)) ok=true;
		c.y++;
		d.x++;
		if(Check(a,c,d)) ok=true;
		d.x-=2;
		if(Check(a,c,d)) ok=true;
		d.x++;
		d.y++;
		if(Check(a,c,d)) ok=true;
		d.y-=2;
		if(Check(a,c,d)) ok=true;
		d.y++;
		if(ok)
		{
			printf("ALMOST\n");
			return 0;
		}
	}
	printf("NEITHER\n");
	return 0;
}