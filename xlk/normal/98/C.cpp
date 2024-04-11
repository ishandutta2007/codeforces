#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int a,b,l;
double f(double x)
{
	return a*cos(x)+b*sin(x)-l*sin(x)*cos(x);
}
int main()
{
	scanf("%d%d%d",&a,&b,&l);
	if(a>b)
		swap(a,b);
	if(l<=b)
		return printf("%d",min(a,l)),0;
	double L=0,R=acos(0);
	for(int _=100;_--;)
	{
		double lm=(L*2+R)/3,rm=(L+R*2)/3;
		if(f(lm)>f(rm))
			L=lm;
		else
			R=rm;
	}
	if(f(L)>1e-9)
		printf("%.16f",min(f(L),(double)l));
	else
		puts("My poor head =(");
	return 0;
}