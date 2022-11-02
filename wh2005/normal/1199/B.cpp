#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath> 
#include <fenv.h>
using namespace std;

double h,l;

int main()
{
	scanf("%lf%lf",&h,&l);
	double x=(l+h)*(l-h);
	double y=2*h;
	double ans=x/y;
	printf("%.13lf",ans);
	return 0;
}