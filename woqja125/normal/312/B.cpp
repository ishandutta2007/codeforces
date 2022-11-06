#include<stdio.h>
int main()
{
	int a, b, c, d;
	double x, y, r;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	x=(long double)a/b;
	y=(long double)c/d;
	r= x/(x+y-x*y);
	printf("%.100lf", r);
}