#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <math.h>
#include <limits>
#include <set>
#include <map>
using namespace std;
double d,h,v,e;
double sqr(double x) {return x*x;}
int main()
{
	scanf("%lf%lf%lf%lf",&d,&h,&v,&e);
	v=v/acos(-1)/sqr(d/2);
	if(v<=e) puts("NO");
	else printf("YES\n%.10lf\n",h/(v-e));
}